#include "test_header2.h"


int main(void)
{
	t_data data;
	size_t size = 100;

	ft_memset(&data, 0, sizeof(t_data));
	data.size = size;
	data.median.size = size;
	data.tab = calloc(data.size, sizeof(int));
	data.median.alloc.tab = calloc(data.size, sizeof(int));
	data.median.fpivot.tab = calloc(data.size, sizeof(int));
	fillstruct(&data);
	bfprt_main(&data);
	return (0);
}

void	fillstruct(t_data *data)
{
	size_t  i = 0;
	size_t  j = 0;

	while ((int)i < data->size)
	{
		data->median.alloc.tab[i] = (int)j;
		data->median.fpivot.tab[i] = (int)j;
		data->tab[i] = (int)j;
		i++;
		j++;
	}
}

void	bfprt_main(t_data *data)
{
	init_var(data);
	get_pivot(data);
	updated_list_generator(data);
}

void	get_pivot(t_data *data)
{
	alloc_tab(data);
	medians_extractor(data);
}

void	init_var(t_data *data)
{
	if (data->median.size == data->size)
		data->median.target = data->size / 2;
	if (data->median.size % 5 == 0)
	{
		data->median.gn = data->median.size / 5;
		data->median.fpivot.gn = data->median.gn;
		data->median.lgs = 5;
		data->median.fpivot.lgs = data->median.lgs;
	}
	else
	{
		data->median.gn = data->median.size / 5 + 1;
		data->median.fpivot.gn = data->median.gn;
		data->median.lgs = data->median.size % 5;
		data->median.fpivot.lgs = data->median.lgs;
	}
	data->median.pivot = 0;
	data->median.pivotindex = 0;
}

void	alloc_tab(t_data *data)
{
	data->median.fpivot.tot = calloc(data->median.fpivot.gn, sizeof(int *));
	if (!data->median.fpivot.tot)
		exiter(data);
	group_maker(data);
	group_filler(data);
}

void	group_maker(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median.fpivot.gn - 1)
	{
		data->median.fpivot.tot[i] = calloc(5, sizeof(int));
		if (!data->median.fpivot.tot[i])
			exiter(data);
		i++;
	}
	data->median.fpivot.tot[i] = calloc(data->median.fpivot.lgs, sizeof(int));
	if (!data->median.fpivot.tot[i])
		exiter(data);
}

void	group_filler(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < data->median.fpivot.gn - 1)
	{
		j = 0;
		while (j < 5)
		{
			data->median.fpivot.tot[i][j] = data->median.fpivot.tab[k];
			j++;
			k++;
		}
		i++;
	}
	j = 0;
	while (j < data->median.fpivot.lgs)
	{
		data->median.fpivot.tot[i][j] = data->median.fpivot.tab[k];
		j++;
	}
}

void	medians_extractor(t_data *data)
{
	group_sorter(data);
	median_group_maker(data);
	if (data->median.fpivot.gn > 5)
		here_we_go_again(data);
	if (data->median.fpivot.gn < 5 && data->median.fpivot.gn > 1)
		pivot_found(data);
	if (data->median.fpivot.gn == 1)
	{
		data->median.pivot = data->median.fpivot.medians[data->median.fpivot.gn / 2];
		pivot_index_finder(data);
		free(data->median.fpivot.medians);
	}
}

void	group_sorter(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median.fpivot.gn - 1)
	{
		sort_int_tab(data->median.fpivot.tot[i], 5);
		i++;
	}
	sort_int_tab(data->median.fpivot.tot[i], data->median.fpivot.lgs);
}

void	sort_int_tab(int *tab, int size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while ((int)i < size -1)
	{
		j = i + 1;
		while ((int)j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				i = 0;
			}
			j++;
		}
		i++;
	}
}

void	median_group_maker(t_data *data)
{
	size_t	i;

	i = 0;
	data->median.fpivot.medians = calloc(data->median.fpivot.gn, sizeof(int));
	if (!data->median.fpivot.medians)
		exiter(data);
	while (i < data->median.fpivot.gn - 1)
	{
		data->median.fpivot.medians[i] = data->median.fpivot.tot[i][3];
		i++;
	}
	data->median.fpivot.medians[i] = data->median.fpivot.tot[i][data->median.fpivot.lgs /2];
	free_tot(data->median.fpivot.gn, data);
}

void	free_tot(size_t i, t_data *data)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(data->median.fpivot.tot[j]);
		j++;
	}
	free(data->median.fpivot.tot);
	data->median.fpivot.tot = NULL;	
}

void	here_we_go_again(t_data *data)
{
	fpivottab_reinit(data);
	if (data->median.fpivot.gn % 5 == 0)
	{
		data->median.fpivot.gn = data->median.fpivot.gn / 5;
		data->median.fpivot.lgs = 5;
	}
	else
	{
		data->median.fpivot.gn = data->median.fpivot.gn / 5 + 1;
		data->median.fpivot.gn = data->median.fpivot.gn % 5;
	}
	free(data->median.fpivot.medians);
	get_pivot(data);
}

void	fpivottab_reinit(t_data *data)
{
	size_t	i;

	i = 0;
	free(data->median.fpivot.tab);
	data->median.fpivot.tab = calloc(data->median.fpivot.gn, sizeof(int));
	if (!data->median.fpivot.tab)
		exiter(data);
	while (i < data->median.fpivot.gn)
	{
		data->median.fpivot.tab[i] = data->median.fpivot.medians[i];
		i++;
	}
}

void	pivot_found(t_data *data)
{
	sort_int_tab(data->median.fpivot.medians, (int)data->median.fpivot.gn);
	data->median.pivot = data->median.fpivot.medians[data->median.fpivot.gn / 2];
	pivot_index_finder(data);
	free(data->median.fpivot.medians);
}

void	pivot_index_finder(t_data *data)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while ((int)i < data->median.size)
	{
		if (data->median.alloc.tab[i] < data->median.pivot)
			j++;
		i++;
	}
	data->median.pivotindex = (int)j;
}

void	updated_list_generator(t_data *data)
{
	if (data->median.target == data->median.pivotindex)
		median_found(data);
	if (data->median.pivotindex > data->median.target)
		pivot_is_bigger(data);
	if (data->median.pivotindex < data->median.target)
		pivot_is_smaller(data);
	if (!data->medianvalue)
		bfprt_main(data);
}

void	pivot_is_bigger(t_data *data)
{
	data->median.i = 1;
	data->median.size = data->median.size - (data->median.size - data->median.pivotindex);
	free(data->median.alloc.tab);
	free(data->median.fpivot.tab);
	data->median.alloc.tab = calloc(data->median.size, sizeof(int));
	data->median.fpivot.tab = calloc(data->median.size, sizeof(int));
	if (!data->median.alloc.tab || !data->median.fpivot.tab)
		exiter(data);
	fill_updated_list(data);
}

void	pivot_is_smaller(t_data *data)
{
	data->median.target = data->median.target - data->median.pivotindex;
	data->median.i = 0;
	data->median.size = data->median.size - data->median.pivotindex;
	free(data->median.alloc.tab);
	free(data->median.fpivot.tab);
	data->median.alloc.tab = calloc(data->median.size, sizeof(int));
	data->median.fpivot.tab = calloc(data->median.size, sizeof(int));
	if (!data->median.alloc.tab || !data->median.fpivot.tab)
		exiter(data);
	fill_updated_list(data);

}

void	fill_updated_list(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < data->median.size)
	{
		if (data->median.i == 1 && data->tab[i] < data->median.pivot)
		{
			data->median.alloc.tab[j] = data->tab[i];
			data->median.fpivot.tab[j] = data->tab[i];
			j++;
		}
		if (data->median.i == 0 && data->tab[i] > data->median.pivot)
		{
			data->median.alloc.tab[j] = data->tab[i];
			data->median.fpivot.tab[j] = data->tab[i];
			j++;
		}
		i++;
	}
}

void	median_found(t_data *data)
{
	free(data->median.fpivot.tab);
	free(data->median.alloc.tab);
	data->medianvalue = data->median.pivot;
}

void	exiter(t_data *data)
{
	if (data->median.alloc.tab)
		free(data->median.alloc.tab);
	if (data->median.fpivot.medians)
		free(data->median.fpivot.medians);
	if (data->median.fpivot.tab)
		free(data->median.fpivot.tab);
	if (data->median.fpivot.tot)
		free_tot(data->median.fpivot.gn, data);
	if (data->tab)
		free(data->tab);
	exit (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*retour;
	unsigned char	t;

	t = (unsigned char)c;
	retour = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		retour[i] = t;
		i++;
	}
	return (retour);
}
