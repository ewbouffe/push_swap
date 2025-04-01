#include "clean_test_header.h"

// problemes a gerer avec la recursivite : probleme de taille du dernier groupe (a regler), dans le cas du dernier groupe le gn - 1 = 0 donc il y a potentiellement des read jusqu'a 5 sur un tab < 5 (a regler)
void	group_maker(t_data *data)
{
	// printf("[%d](group_maker)\n", data->bfprt.fpivot.counter);
	size_t  i;

	i = 0;
	while (i < data->bfprt.fpivot.gn - 1 && data->bfprt.fpivot.gn != 1)
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
	// printf("[%d](group_filler)\n", data->bfprt.fpivot.counter);
	while (i < data->bfprt.fpivot.gn - 1 && data->bfprt.fpivot.gn != 1)
	{
		j = 0;
		while (j < 5)
		{
			data->bfprt.fpivot.tot[i][j] = data->bfprt.fpivot.tab[k];
				// printf("[%d](group_filler) tot[%zu][%zu] = %d, tab[%zu] = %d\n", data->bfprt.fpivot.counter, i, j, data->bfprt.fpivot.tot[i][j], k, data->bfprt.fpivot.tab[k]);
			j++;
			k++;
		}
		i++;
	}
	j = 0;
	while (j < data->bfprt.fpivot.lgs)
	{
		data->bfprt.fpivot.tot[i][j] = data->bfprt.fpivot.tab[k];
			// printf("[%d](group_filler) tot[%zu][%zu] = %d, tab[%zu] = %d\n", data->bfprt.fpivot.counter, i, j, data->bfprt.fpivot.tot[i][j], k, data->bfprt.fpivot.tab[k]);
		j++;
		k++;
	}
}

void	medians_extractor(t_data *data)
{
	// printf("[%d](medians_extractor)\n", data->bfprt.fpivot.counter);
	group_sorter(data);
	median_group_maker(data);
	// printf("[%d](medians_extractor) fpivot.gn = %zu\n[%d](medians_extractor) fpivot.lgs = %zu\n", data->bfprt.fpivot.counter, data->bfprt.fpivot.gn, data->bfprt.fpivot.counter, data->bfprt.fpivot.lgs);
	// size_t	i = 0;
	// while (i < data->bfprt.fpivot.gn)
	// {
	// 	printf("[%d] medians[%zu] : %d\n", data->bfprt.fpivot.counter, i, data->bfprt.fpivot.medians[i]);
	// 	i++;
	// }
	if (data->bfprt.fpivot.gn == 1)
	{
		data->bfprt.pivot = data->bfprt.fpivot.medians[0];
		printf("[%d][%d](medians_extractor) pivot = %d\n", data->bfprt.iteration, data->bfprt.fpivot.counter, data->bfprt.pivot);
		pivot_index_finder(data);
		free(data->bfprt.fpivot.medians);
	}
	else 
		here_we_go_again(data);
}

void	group_sorter(t_data *data)
{
	// printf("[%d](group_sorter)\n", data->bfprt.fpivot.counter);
	size_t	i;

	i = 0;
	// size_t	j = 0;
	while (i < data->bfprt.fpivot.gn - 1)
	{
		sort_int_tab(data->bfprt.fpivot.tot[i], 5);
		// j = 0;
		// while (j < 5)
		// {
		// 	// printf("sorted tab[%zu][%zu] = %d\n", i, j , data->bfprt.fpivot.tot[i][j]);
		// 	j++;
		// }
		i++;
	}
	sort_int_tab(data->bfprt.fpivot.tot[i], data->bfprt.fpivot.lgs);
}

void	median_group_maker(t_data *data)
{
	// printf("[%d](median_group_maker)\n", data->bfprt.fpivot.counter);
	size_t	i;

	i = 0;
	data->bfprt.fpivot.medians = calloc(data->bfprt.fpivot.gn, sizeof(int));
	if (!data->bfprt.fpivot.medians)
		exiter(data);
	while (i < data->bfprt.fpivot.gn - 1 && data->bfprt.fpivot.gn != 1)
	{
		data->bfprt.fpivot.medians[i] = data->bfprt.fpivot.tot[i][2];
		i++;
	}
	data->bfprt.fpivot.medians[i] = data->bfprt.fpivot.tot[i][data->bfprt.fpivot.lgs / 2];
	free_tot(data->bfprt.fpivot.gn, data);
}


void	here_we_go_again(t_data *data)
{
	// printf("[%d](here_we_go_again)\n", data->bfprt.fpivot.counter);
	// fpivottab_reinit(data);
	free(data->bfprt.fpivot.tab);
	// printf("\n[%d](herewegoagain) fpivot.gn = %zu\n[%d](herewegoagain) fpivot.lgs = %zu\n", data->bfprt.fpivot.counter, data->bfprt.fpivot.gn, data->bfprt.fpivot.counter, data->bfprt.fpivot.lgs);
	data->bfprt.fpivot.tab = calloc(data->bfprt.fpivot.gn, sizeof(int));
	if (!data->bfprt.fpivot.tab)
		exiter(data);
	data->bfprt.fpivot.tab = ft_memcpy(data->bfprt.fpivot.tab, data->bfprt.fpivot.medians, data->bfprt.fpivot.gn * sizeof(int));
	free(data->bfprt.fpivot.medians);
	// size_t	i = 0;
	// while (i < data->bfprt.fpivot.gn)
	// {
	// 	printf("[%d](herewegoagain) fpivot.tab[%zu] = %d\n", data->bfprt.fpivot.counter, i, data->bfprt.fpivot.tab[i]);
	// 	i++;
	// }
	if (data->bfprt.fpivot.gn <= 5)
	{
		if (data->bfprt.fpivot.gn % 5 == 0)
		{
			// printf("[%d](here_we_go_again) : 1\n", data->bfprt.fpivot.counter);
			data->bfprt.fpivot.lgs = 5;
		}
		if (data->bfprt.fpivot.gn % 5 != 0)
		{
			// printf("[%d](here_we_go_again) : 2\n", data->bfprt.fpivot.counter);
			data->bfprt.fpivot.lgs = data->bfprt.fpivot.gn % 5;
		}
		data->bfprt.fpivot.gn = 1;
	}
	if (data->bfprt.fpivot.gn % 5 == 0 && data->bfprt.fpivot.gn > 5)
	{
		// printf("[%d](here_we_go_again) : 3\n", data->bfprt.fpivot.counter);
		data->bfprt.fpivot.lgs = 5;
		data->bfprt.fpivot.gn = data->bfprt.fpivot.gn / 5;
	}
	if (data->bfprt.fpivot.gn % 5 != 0 && data->bfprt.fpivot.gn > 5)
	{
		// printf("[%d](here_we_go_again) : 4\n", data->bfprt.fpivot.counter);
		data->bfprt.fpivot.lgs = data->bfprt.fpivot.gn % 5;
		data->bfprt.fpivot.gn = data->bfprt.fpivot.gn / 5 + 1;
	}
	// printf("[%d](here_we_go_again) apres assign valeurs :\nfpivot.gn = %zu\nfpivot.lgs = %zu\n", data->bfprt.fpivot.counter, data->bfprt.fpivot.gn, data->bfprt.fpivot.lgs);
	get_pivot(data);
}

// void	fpivottab_reinit(t_data *data)
// {
// 	free(data->bfprt.fpivot.tab);
// 	data->bfprt.fpivot.tab = calloc(data->bfprt.fpivot.gn, sizeof(int));
// 	if (!data->bfprt.fpivot.tab)
// 		exiter(data);
// 	data->bfprt.fpivot.tab = ft_memcpy(data->bfprt.fpivot.tab, data->bfprt.fpivot.medians, data->bfprt.fpivot.gn);
// 	free(data->bfprt.fpivot.medians);
// }

void	pivot_index_finder(t_data *data)
{
	// printf("[%d](pivot_index_finder)\n", data->bfprt.fpivot.counter);
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
