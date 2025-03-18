#include <stdio.h>
#include "test_header.h"
#include <strings.h>

void	init_struct(t_data *data);

// int main(int c, char **v)
// {
// 	(void) c;
// 	size_t	i = 0;
// 	size_t	j = 0;
// 	t_data data;
	
// 	ft_memset(&data, 0, sizeof(t_data));
// 	init_struct(&data);
// 	main_parsing(v, &data);
// 	if (data.parsing_error == 1)
// 	{
// 		free(data.tab);
// 		print_error();
// 		exit (0);
// 	}
// 	bfprt_main(&data);
// 	while (i < data.median->groupnumber - 1)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			printf("%d ", data.median->alloc->gfive[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	j = 0;
// 	i++;
// 	while (j < data.median->lastgroupsize)
// 	{
// 		printf("%d", data.median->alloc->gfive[i][j]);
// 		j++;
// 	}
// 	printf("\n");
// 	return (0);
// }

void	init_struct(t_data *data)
{
	data->median = calloc(1, sizeof(t_median));
	if (!data->median)
		return ;
	ft_memset(data->median, 0, sizeof(t_median));
	data->median->alloc = calloc(1, sizeof(t_median_alloc));
	if (!data->median->alloc)
		return ;
	ft_memset(data->median->alloc, 0, sizeof(t_median_alloc));
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
	//get_medians(data);
	// get_median(data);
	// make_next_list(data);
	// if (data->medianvalue == 0)
	// 	find_pivot(data);
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
