#include "test_header2.h"
#include <string.h>

int main(void)
{
	t_data data;
	size_t size = 100;
	// size_t	i = 0;
	int	tab[100] = {472, 85, 361, 918, 237, 654, 129, 743, 50, 812, 305, 687, 921, 134, 578, 399, 246, 835, 740, 269, 527, 184, 620, 311, 953, 78, 410, 586, 144, 873, 91, 232, 670, 328, 499, 213, 752, 631, 94, 555, 802, 379, 268, 922, 41, 590, 710, 358, 621, 149, 814, 207, 435, 963, 281, 537, 672, 86, 120, 311, 904, 768, 239, 446, 525, 689, 154, 378, 99, 802, 195, 607, 481, 132, 740, 286, 918, 365, 159, 775, 429, 98, 534, 742, 664, 872, 190, 643, 272, 550,  941, 313, 214, 895, 771, 258, 688, 579, 322, 503};

	ft_memset(&data, 0, sizeof(t_data));
	data.size = size;
	data.median.size = size;
	data.tab = calloc(data.size, sizeof(int));
	data.median.alloc.tab = calloc(data.size, sizeof(int));
	data.median.fpivot.tab = calloc(data.size, sizeof(int));
	// fillstruct(&data);
	memcpy(data.tab, tab, 100 * sizeof(int));
	memcpy(data.median.alloc.tab, tab, 100 * sizeof(int));
	memcpy(data.median.fpivot.tab, tab, 100 * sizeof(int)); 
	bfprt_main(&data);
	// printf("median size %d\n", data.median.size);
	// printf("median gn   %zu\n", data.median.gn);
	// printf("fpivot gn   %zu\n", data.median.fpivot.gn);
	// printf("median lgs  %zu\n", data.median.lgs);
	// printf("fpivot lgs  %zu\n", data.median.fpivot.lgs);
	// printf("%d", );
	// printf("%d", );
	// printf("%d", );
	// printf("%d", );
	// printf("%d", );
	printf("rang de la mediane dans la nouvelle liste %d\n", data.median.target);
	printf("index %d, rang de l'index %d\n", data.median.pivot, data.median.pivotindex);
	printf("tout vas bien\n");
	free(data.tab);
	free(data.median.alloc.tab);
	free(data.median.fpivot.tab);
	// free(data.median.fpivot.medians);
	// free_tot(data.median.fpivot.gn, &data);
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

void	bfprt_main(t_data *data)
{
	init_var(data); // fonctionnel
	get_pivot(data); // fonctionnel en solo
	updated_list_generator(data);
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
	// printf("median size %d\n", data->median.size);
	// printf("median gn   %zu\n", data->median.gn);
	// printf("fpivot gn   %zu\n", data->median.fpivot.gn);
	// printf("median lgs  %zu\n", data->median.lgs);
	// printf("fpivot lgs  %zu\n", data->median.fpivot.lgs);
}

void	get_pivot(t_data *data)
{
	// size_t	i = 0, j = 0; 
	alloc_tab(data);
	medians_extractor(data);

	// while (i < data->median.fpivot.gn - 1)
	// {
	// 	j = 0;
	// 	printf("tab [i] = ");
	// 	while (j < 5)
	// 	{
	// 		printf("%d, ", data->median.fpivot.tot[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// j = 0;
	// printf("dernier tab = ");
	// while (j < data->median.fpivot.lgs)
	// {
	// 	printf("%d, ", data->median.fpivot.tot[i][j]);
	// 	j++;
	// }
	// printf ("\n");
}

void	alloc_tab(t_data *data) // fonctionne bien
{
	// size_t	y = 0, z =0;
	data->median.fpivot.tot = calloc(data->median.fpivot.gn, sizeof(int *));
	if (!data->median.fpivot.tot)
		exiter(data);
	group_maker(data);
	group_filler(data);

// 	while (y < data->median.fpivot.gn - 1)
// 	{
// 		z = 0;
// 		printf("tab non trie [i] = ");
// 		while (z < 5)
// 		{
// 			printf("%d, ", data->median.fpivot.tot[y][z]);
// 			z++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	z = 0;
// 	printf("dernier tab non trie = ");
// 	while (z < data->median.fpivot.lgs)
// 	{
// 		printf("%d, ", data->median.fpivot.tot[y][z]);
// 		z++;
// 	}
// 	printf ("\n");
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

void	group_maker(t_data *data) //fonctionne bien
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

void	group_filler(t_data *data) //fonctionne bien
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
		k++;
	}
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

void	medians_extractor(t_data *data)
{
	// size_t	y = 0, z = 0;
	group_sorter(data);
	// while (y < data->median.fpivot.gn - 1)
	// {
	// 	z = 0;
	// 	printf("tab trie [i] = ");
	// 	while (z < 5)
	// 	{
	// 		printf("%d, ", data->median.fpivot.tot[y][z]);
	// 		z++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	// z = 0;
	// printf("dernier tab trie = ");
	// while (z < data->median.fpivot.lgs)
	// {
	// 	printf("%d, ", data->median.fpivot.tot[y][z]);
	// 	z++;
	// }
	// printf ("\n");
	median_group_maker(data);
	// y = 0, z = 0;
	// printf("tableau de medianes = ");
	// while (y < data->median.fpivot.gn)
	// {
	// 	printf("%d, ", data->median.fpivot.medians[y]);
	// 	y++;
	// }
	// printf("\n");
	if (data->median.fpivot.gn <= 1 && data->median.fpivot.lgs == 1)
	{
		data->median.pivot = data->median.fpivot.medians[0];
		pivot_index_finder(data);
		free(data->median.fpivot.medians);
	}
	else if (data->median.fpivot.gn <= 1 && data->median.fpivot.lgs != 1)
	{
		group_sorter(data);
		data->median.pivot = data->median.fpivot.medians[data->median.fpivot.lgs / 2];
		pivot_index_finder(data);
		free(data->median.fpivot.medians);
	}
	else 
		here_we_go_again(data);
}

void	group_sorter(t_data *data) //fonctionne
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

void	sort_int_tab(int *tab, int size) //fonctionne
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

void	median_group_maker(t_data *data) // fonctionne
{
	size_t	i;

	i = 0;
	data->median.fpivot.medians = calloc(data->median.fpivot.gn, sizeof(int));
	if (!data->median.fpivot.medians)
		exiter(data);
	while (i < data->median.fpivot.gn - 1)
	{
		data->median.fpivot.medians[i] = data->median.fpivot.tot[i][2];
		i++;
	}
	data->median.fpivot.medians[i] = data->median.fpivot.tot[i][data->median.fpivot.lgs /2];
	free_tot(data->median.fpivot.gn, data);
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
		data->median.fpivot.lgs = data->median.fpivot.gn % 5;
	}
	free(data->median.fpivot.medians);
	// printf("median size %d\n", data->median.size);
	// printf("median gn   %zu\n", data->median.gn);
	// printf("fpivot gn   %zu\n", data->median.fpivot.gn);
	// printf("median lgs  %zu\n", data->median.lgs);
	// printf("fpivot lgs  %zu\n", data->median.fpivot.lgs);
	get_pivot(data);
}

void	fpivottab_reinit(t_data *data)
{
	free(data->median.fpivot.tab);
	data->median.fpivot.tab = calloc(data->median.fpivot.gn, sizeof(int));
	if (!data->median.fpivot.tab)
		exiter(data);
	memcpy(data->median.fpivot.tab, data->median.fpivot.medians, data->median.fpivot.gn * sizeof(int));
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
}

void	pivot_is_bigger(t_data *data)
{
	data->median.i = 1;
	data->median.oldsize = data->median.size;
	data->median.size = data->median.size - (data->median.size - data->median.pivotindex);
	free(data->median.alloc.tab);
	free(data->median.fpivot.tab);
	data->median.alloc.tab = calloc(data->median.size, sizeof(int));
	data->median.fpivot.tab = calloc(data->median.size, sizeof(int));
	if (!data->median.alloc.tab || !data->median.fpivot.tab)
		exiter(data);
	fill_updated_list(data);
	bfprt_main(data);
}

void	pivot_is_smaller(t_data *data)
{
	data->median.i = 0;
	data->median.oldsize = data->median.size;
	data->median.target = data->median.target - data->median.pivotindex;
	data->median.size = data->median.size - data->median.pivotindex;
	free(data->median.alloc.tab);
	free(data->median.fpivot.tab);
	data->median.alloc.tab = calloc(data->median.size, sizeof(int));
	data->median.fpivot.tab = calloc(data->median.size, sizeof(int));
	if (!data->median.alloc.tab || !data->median.fpivot.tab)
		exiter(data);
	fill_updated_list(data);
	bfprt_main(data);
}

void	fill_updated_list(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	// while ((int)i < data->size)
	// {
	// 	printf("%d, ", data->tab[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	printf("oldsize = %d\nnouvelle taille %d\nrang du pivot %d\npivot %d\n", data->median.oldsize, data->median.size, data->median.pivotindex, data->median.pivot);
	while ((int)i < data->median.oldsize)
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
	// i = 0, j = 0;
	// printf("nouvelle liste = ");
	// while ((int)i < data->median.size)
	// {
	// 	printf("%d, ", data->median.alloc.tab[i]);
	// 	i++;
	// }
	// printf("\n");
}

void	median_found(t_data *data)
{
	free(data->median.fpivot.tab);
	free(data->median.alloc.tab);
	data->medianvalue = data->median.pivot;
}
