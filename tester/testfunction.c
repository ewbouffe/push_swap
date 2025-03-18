#include <stdio.h>
#include "test_header.h"
#include <strings.h>
void    sortie(t_data *data);
void    fillstruct(t_data *data);


int main(void)
{
	// size_t	i = 0;
	// size_t	j = 0;
	t_data data;
    size_t size = 83;
	
	ft_memset(&data, 0, sizeof(t_data));
    data.size = size;
	data.median.size = size;
    data.tab = calloc(data.size, sizeof(int));
    data.median.alloc.tab = calloc(data.size, sizeof(int));
    fillstruct(&data);
	bfprt_main(&data);
	printf("groupnumber   %zu\n", data.median.groupnumber);
	printf("lastgroupsize %zu\n", data.median.lastgroupsize);
	printf("pivot         %d\n", data.median.pivot);
	printf("pivotindex    %d\n", data.median.pivotindex);
	printf("median.size   %d\n", data.median.size);
	printf("size          %d\n", data.size);
    // sortie(&data);
    return (0);
}

// cc -Wall -Wextra -Werror parsingtest.c testfunction.c -g3 -o test && valgrind ./test

void    sortie(t_data *data)
{
    if (data->tab)
        free(data->tab);
    if (data->median.alloc.tab)
        free(data->median.alloc.tab);
}

void    fillstruct(t_data *data)
{
    size_t  i = 0;
    size_t  j = 0;

    while ((int)i < data->size)
    {
        data->median.alloc.tab[i] = (int)j;
        data->tab[i] = (int)j;
        i++;
        j++;
    }
}

void	bfprt_main(t_data *data)
{
	find_pivot(data);
	return ;
}

void	find_pivot(t_data *data)
{
	init_var(data);
	group_init(data);
	get_medians(data);
	get_median(data);
	make_next_list(data);
	// if (data->medianvalue == 0)
	// 	find_pivot(data);
	return ;
}

void	init_var(t_data *data)
{
	if (data->size % 5 == 0)
	{
		data->median.groupnumber = data->median.size / 5;
		data->median.lastgroupsize = 5;
	}
	else
	{
		data->median.groupnumber = data->median.size / 5 + 1;
		data->median.lastgroupsize = data->median.size % 5;
	}
	data->median.target = data->median.size / 2;
	data->median.pivot = 0;
	data->median.pivotindex = 0;
}

void	group_init(t_data *data)
{
	data->median.alloc.gfive = malloc(sizeof(int *) * data->median.groupnumber);
	if (!data->median.alloc.gfive)
		exiter (data);
	alloc_tabs(data);
	fill_tabs(data);
}

void	alloc_tabs(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median.groupnumber - 1)
	{
		data->median.alloc.gfive[i] = malloc(sizeof(int) * 5);
		if (!data->median.alloc.gfive[i])
			free_tabs(i, data);
		i++;
	}
	data->median.alloc.gfive[i] = malloc(sizeof(int) * data->median.lastgroupsize);
	if (!data->median.alloc.gfive[i])
		free_tabs(i, data);
}

void	free_tabs(size_t i, t_data *data)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(data->median.alloc.gfive[j]);
		j++;
	}
	free(data->median.alloc.gfive);
	data->median.alloc.gfive = NULL;
}

void	fill_tabs(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < data->median.groupnumber - 1)
	{
		j = 0;
		while (j < 5)
		{
			data->median.alloc.gfive[i][j] = data->median.alloc.tab[k];
			//printf("tab[%zu][%zu] = %d, original = %d\n", i, j, data->median.alloc.gfive[i][j], data->median.alloc.tab[k]);
			j++;
			k++;
		}
		i++;
	}
	j = 0;
	while (j < data->median.lastgroupsize)
	{
		data->median.alloc.gfive[i][j] = data->median.alloc.tab[k];
		//printf("lastab[%zu][%zu] = %d, original = %d\n", i, j, data->median.alloc.gfive[i][j], data->median.alloc.tab[k]);
		j++;
		k++;
	}
}

void	exiter(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->median.alloc.kept)
		free(data->median.alloc.kept);
	if (data->median.alloc.tab)
		free(data->median.alloc.tab);
	if (data->median.alloc.gfive)
	{
		while (i < data->median.groupnumber)
		{
			free(data->median.alloc.gfive[i]);
			i++;
		}
		free(data->median.alloc.gfive);
	}
	if (data->median.alloc.medians)
		free(data->median.alloc.medians);
	print_error();
	exit (1);
}

void	get_medians(t_data *data)
{
	size_t	i;
	
	i = 0;
	sort_int_tab(data);
	data->median.alloc.medians = malloc(sizeof(int) * data->median.groupnumber);
	if (!data->median.alloc.medians)
		exiter(data);
	while (i < data->median.groupnumber - 1)
	{
		data->median.alloc.medians[i] = data->median.alloc.gfive[i][3];
		i++;
	}
	data->median.alloc.medians[i] = data->median.alloc.gfive[i][data->median.lastgroupsize / 2];
	// i = 0;
	// while (i < data->median.groupnumber)
	// {
	// 	printf("%d, ", data->median.alloc.medians[i]);
	// 	i++;
	// }
	// printf("\n");
	free_tabs(data->median.groupnumber, data);
}

void	sort_int_tab(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median.groupnumber - 1)
	{
		medians_sorter(data->median.alloc.gfive[i], 5);
		i++;
	}
	medians_sorter(data->median.alloc.gfive[i], data->median.lastgroupsize);
}

int	*medians_sorter(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i = 0;
		}
		i++;
	}
	return (tab);
}

void	get_median(t_data *data)
{
	medians_sorter(data->median.alloc.medians, data->median.groupnumber);
	data->median.pivot = data->median.alloc.medians[data->median.groupnumber / 2];
	free(data->median.alloc.medians);
}

void	make_next_list(t_data *data)
{
	size_t	i;

	i = 0;
	pivot_index_finder(data);
	if (data->median.alloc.kept)
		free(data->median.alloc.kept);
	if (data->median.pivotindex == data->median.target)
		data->medianvalue = data->median.pivot;
	if (data->median.pivotindex > data->median.target)
	{
		data->median.size = data->median.pivotindex;
		data->median.alloc.kept = malloc (sizeof(int) * data->median.size);
		if (!data->median.alloc.kept)
			exiter(data);
		fill_next_list_btt(data);
	}
	if (data->median.pivotindex < data->median.target)
	{
		data->median.size = data->median.size - data->median.pivotindex;
		data->median.alloc.kept = malloc(sizeof(int) * data->median.size);
		if (!data->median.alloc.kept)
			exiter(data);
		fill_next_list_stt(data);
	}
	make_new_tab(data);
}

void	pivot_index_finder(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->median.alloc.tab[i])
	{
		if (data->median.alloc.tab[i] < data->median.pivot)
			data->median.pivotindex++;
		i++;
	}
}

void	fill_next_list_btt(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < data->size)
	{
		if (data->median.alloc.tab[i] < data->median.pivot)
		{
			data->median.alloc.kept[j] = data->median.alloc.tab[i];
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
	while ((int)i < data->size)
	{
		if (data->median.alloc.tab[i] > data->median.pivot)
		{
			data->median.alloc.kept[j] = data->median.alloc.tab[i];
			j++;
		}
		i++;
	}
}

void	make_new_tab(t_data *data)
{
	if (data->median.alloc.tab)
		free(data->median.alloc.tab);
	// data->median.alloc.tab = ft_strdup(data->median.alloc.kept);
	if (!data->median.alloc.tab)
		exiter(data);
}
