#include "../include/ft_push_swap.h"

void	bfprt_main(t_data *data)
{
	data->median->alloc->tab = ft_strdup(data->tab);
	if (!data->median->alloc->kept)
		exiter(data);
	find_pivot(data);
	return ;
}

void	find_pivot(t_data *data)
{
	init_var(data);
	groups_init(data);
	get_medians(data);
	get_median(data);
	make_next_list(data);
	if (data->medianvalue == 0)
		find_pivot(data);
	return ;
}

void	init_var(t_data *data)
{
	if (data->size % 5 == 0)
	{
		data->median->groupnumber = data->median->size / 5;
		data->median->lastgroupsize = data->median->size % 5;
	}
	else
	{
		data->median->groupnumber = data->median->size / 5 + 1;
		data->median->lastgroupsize = data->median->size % 5;
	}
	data->median->target = data->median->size / 2 + 1;
	data->median->pivot = 0;
	data->median->pivotindex = 0;
}

void	group_init(t_data *data)
{
	data->median->alloc->gfive = malloc(sizeof(int *) * data->median->groupnumber);
	if (!data->median->alloc->gfive)
		exiter (data);
	alloc_tabs(data);
	fill_tabs(data);
}

void	alloc_tabs(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median->groupnumber - 1)
	{
		data->median->alloc->gfive[i] = malloc(sizeof(int) * 5);
		if (!data->median->alloc->gfive[i])
			free_tabs(i, data);
		i++;
	}
	data->median->alloc->gfive[i] = malloc(sizeof(int) * data->median->lastgroupsize);
	if (!data->median->alloc->gfive[i])
		free_tabs(i, data);
}

void	free_tabs(size_t i, t_data *data)
{
	i--;
	while (i > 0)
	{
		free(data->median->alloc->gfive[i]);
		i--;
	}
	free(data->median->alloc->gfive);
	data->median->alloc->gfive = NULL;
	exiter(data);
}

void	fill_tabs(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < data->median->groupnumber - 1)
	{
		j = 0;
		while (j < 5)
		{
			data->median->alloc->gfive[i][j] = data->median->alloc->tab[k];
			j++;
			k++;
		}
		i++;
	}
	while (j < data->median->lastgroupsize)
	{
		j = 0;
		data->median->alloc->gfive[i][j] = data->median->alloc->tab[k];
		j++;
		k++;
	}
}

void	get_medians(t_data *data)
{
	size_t	i;
	
	i = 0;
	while (i < data->median->groupnumber)
	{
		data->median->alloc->gfive[i] = sort_int_tab(data->median->alloc->gfive[i]);
		i++;
	}
	i = 0;
	data->median->alloc->medians = malloc(sizeof(int) * data->median->groupnumber);
	if (!data->median->alloc->medians)
	exiter(data);
	while (i < data->median->groupnumber - 1)
	{
		data->median->alloc->medians[i] = data->median->alloc->gfive[i][3];
		i++;
	}
	data->median->alloc->medians[i] = data->median->alloc->gfive[i][data->median->lastgroupsize / 2];
	free_tabs(i, data);
}

void	get_median(t_data *data)
{
	data->median->alloc->medians = sort_int_tab(data->median->alloc->medians);
	data->median->pivot = data->median->alloc->medians[data->median->groupnumber / 2 + 1];
	free(data->median->alloc->medians);
}

void	make_next_list(t_data *data)
{
	size_t	i;

	i = 0;
	pivot_index_finder(data);
	if (data->median->alloc->kept)
		free(data->median->alloc->kept);
	if (data->median->pivotindex == data->median->target)
		data->medianvalue = data->median->pivot;
	if (data->median->pivotindex > data->median->target)
	{
		data->median->size = data->median->pivotindex;
		data->median->alloc->kept = malloc (sizeof(int) * data->median->size);
		if (!data->median->alloc->kept)
			exiter(data);
		fill_next_list_btt(data);
	}
	if (data->median->pivotindex < data->median->target)
	{
		data->median->size = data->median->size - data->median->pivotindex;
		data->median->alloc->kept = malloc(sizeof(int) * data->median->size);
		if (!data->median->alloc->kept)
			exiter(data);
		fill_next_list_stt(data);
	}
	make_new_tab(data);
}

void	pivot_index_finder(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->median->alloc->tab[i])
	{
		if (data->median->alloc->tab[i] < data->median->pivot)
			data->median->pivotindex++;
		i++;
	}
}

void	fill_next_list_btt(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->size)
	{
		if (data->median->alloc->tab[i] < data->median->pivot)
		{
			data->median->alloc->kept[j] = data->median->alloc->tab[i];
			j++;
		}
		i++;
	}
}

void	fill_next_list_stt(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->size)
	{
		if (data->median->alloc->tab[i] > data->median->pivot)
		{
			data->median->alloc->kept = data->median->alloc->tab[i];
			j++;
		}
		i++;
	}
}

void	make_new_tab(t_data *data)
{
	if (data->median->alloc->tab)
		free(data->median->alloc->tab);
	data->median->alloc->tab = ft_strdup(data->median->alloc->kept);
	if (!data->median->alloc->tab)
		exiter(data);
}

void	exiter(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->median->alloc->kept)
		free(data->median->alloc->kept);
	if (data->median->alloc->tab)
		free(data->median->alloc->tab);
	if (data->median->alloc->gfive)
	{
		while (i < data->median->groupnumber)
		{
			free(data->median->alloc->gfive[i]);
			i++;
		}
		free(data->median->alloc->gfive);
	}
	if (data->median->alloc->medians)
		free(data->median->alloc->medians);
	print_error();
	exit (1);
}

