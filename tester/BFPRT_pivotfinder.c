#include "clean_test_header.h"

void	group_maker(t_data *data)
{
	size_t  i;

	i = 0;
	while (i < data->bfprt.fpivot.gn - 1)
	{
		data->bfprt.fpivot.tot[i] = calloc(5, sizeof(int));
		if (!data->bfprt.fpivot.tot[i])
		{
			free_tot(i, data);
			exiter(data);
		}
		i++;
	}
	data->bfprt.fpivot.tot[i] = calloc(data->bfprt.fpivot.lgs, sizeof(int));
	if (!data->bfprt.fpivot.tot[i])
	{
		free_tot(i, data);
		exiter(data);
	}
}

void	group_filler(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < data->bfprt.fpivot.gn - 1)
	{
		j = 0;
		while (j < 5)
		{
			data->bfprt.fpivot.tot[i][j] = data->bfprt.fpivot.tab[k];
			// printf("tot[%zu][%zu] = %d, tab[%zu] = %d\n", i, j, data->bfprt.fpivot.tot[i][j], k, data->bfprt.fpivot.tab[k]);
			j++;
			k++;
		}
		i++;
	}
	j = 0;
	while (j < data->bfprt.fpivot.lgs)
	{
		data->bfprt.fpivot.tot[i][j] = data->bfprt.fpivot.tab[k];
		j++;
		k++;
	}
}

void	medians_extractor(t_data *data)
{
	group_sorter(data);
	median_group_maker(data);
	if (data->bfprt.fpivot.gn <= 1 && data->bfprt.fpivot.lgs == 1)
	{
		data->bfprt.pivot = data->bfprt.fpivot.medians[0];
		pivot_index_finder(data);
		free(data->bfprt.fpivot.medians);
	}
	else if (data->bfprt.fpivot.gn <= 1 && data->bfprt.fpivot.lgs != 1)
	{
		group_sorter(data);
		data->bfprt.pivot = data->bfprt.fpivot.medians[data->bfprt.fpivot.lgs / 2];
		pivot_index_finder(data);
		free(data->bfprt.fpivot.medians);
	}
	else 
		here_we_go_again(data);
}

void	group_sorter(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->bfprt.fpivot.gn - 1)
	{
		sort_int_tab(data->bfprt.fpivot.tot[i], 5);
		i++;
	}
	sort_int_tab(data->bfprt.fpivot.tot[i], data->bfprt.fpivot.lgs);
}

void	median_group_maker(t_data *data)
{
	size_t	i;

	i = 0;
	data->bfprt.fpivot.medians = calloc(data->bfprt.fpivot.gn, sizeof(int));
	if (!data->bfprt.fpivot.medians)
		exiter(data);
	while (i < data->bfprt.fpivot.gn - 1)
	{
		data->bfprt.fpivot.medians[i] = data->bfprt.fpivot.tot[i][2];
		i++;
	}
	data->bfprt.fpivot.medians[i] = data->bfprt.fpivot.tot[i][data->bfprt.fpivot.lgs / 2];
	free_tot(data->bfprt.fpivot.gn, data);
}


void	here_we_go_again(t_data *data)
{
	// fpivottab_reinit(data);
	free(data->bfprt.fpivot.tab);
	printf("\nfpivot.gn(herewegoagain) = %zu\nfpivot.lgs(herewegoagain) = %zu\n", data->bfprt.fpivot.gn, data->bfprt.fpivot.lgs);
	data->bfprt.fpivot.tab = calloc(data->bfprt.fpivot.gn, sizeof(int));
	if (!data->bfprt.fpivot.tab)
		exiter(data);
	data->bfprt.fpivot.tab = ft_memcpy(data->bfprt.fpivot.tab, data->bfprt.fpivot.medians, data->bfprt.fpivot.gn * sizeof(int));
	free(data->bfprt.fpivot.medians);
	size_t	i = 0;
	while (i < data->bfprt.fpivot.gn)
	{
		printf("fpivot.tab(herewegoagain)[%zu] = %d\n", i, data->bfprt.fpivot.tab[i]);
		i++;
	}
	if (data->bfprt.fpivot.gn % 5 == 0)
	{
		data->bfprt.fpivot.gn = data->bfprt.fpivot.gn / 5;
		data->bfprt.fpivot.lgs = 5;
	}
	else
	{
		data->bfprt.fpivot.gn = data->bfprt.fpivot.gn / 5 + 1;
		data->bfprt.fpivot.lgs = data->bfprt.fpivot.gn % 5;
	}
	get_pivot(data);
}

void	fpivottab_reinit(t_data *data)
{
	free(data->bfprt.fpivot.tab);
	data->bfprt.fpivot.tab = calloc(data->bfprt.fpivot.gn, sizeof(int));
	if (!data->bfprt.fpivot.tab)
		exiter(data);
	data->bfprt.fpivot.tab = ft_memcpy(data->bfprt.fpivot.tab, data->bfprt.fpivot.medians, data->bfprt.fpivot.gn);
	free(data->bfprt.fpivot.medians);
}

void	pivot_index_finder(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < data->bfprt.size)
	{
		if (data->bfprt.pivot > data->bfprt.alloc.tab[i])
			j++;
		i++;
	}
	data->bfprt.pivotindex = (int)j;
}
