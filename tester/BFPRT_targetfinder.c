#include "clean_test_header.h"

void	pivot_is_bigger(t_data *data)
{
	data->bfprt.i = 1;
	data->bfprt.oldsize = data->bfprt.size;
	data->bfprt.alloc.oldtab = calloc(data->bfprt.oldsize, sizeof(int));
	if (!data->bfprt.alloc.oldtab)
		exiter(data);
	data->bfprt.alloc.oldtab = ft_memcpy(data->bfprt.alloc.oldtab, data->bfprt.alloc.tab, data->bfprt.oldsize);
	data->bfprt.size = data->bfprt.size - (data->bfprt.size - data->bfprt.pivotindex);
	free(data->bfprt.alloc.tab);
	free(data->bfprt.fpivot.tab);
	data->bfprt.alloc.tab = calloc(data->bfprt.size, sizeof(int));
	data->bfprt.fpivot.tab = calloc(data->bfprt.size, sizeof(int));
	fill_updated_list(data);
	bfprt_main(data);
}

void	pivot_is_smaller(t_data *data)
{
	data->bfprt.i = 0;
	data->bfprt.oldsize =data->bfprt.size;
	data->bfprt.alloc.oldtab = calloc(data->bfprt.oldsize, sizeof(int));
	data->bfprt.target = data->bfprt.target - data->bfprt.pivotindex;
	if (!data->bfprt.alloc.oldtab)
		exiter(data);
	data->bfprt.alloc.oldtab = ft_memcpy(data->bfprt.alloc.oldtab, data->bfprt.alloc.tab, data->bfprt.oldsize);
	data->bfprt.size = data->bfprt.size - data->bfprt.pivotindex;
	free(data->bfprt.alloc.tab);
	free(data->bfprt.fpivot.tab);
	data->bfprt.alloc.tab = calloc(data->bfprt.size, sizeof(int));
	data->bfprt.fpivot.tab = calloc(data->bfprt.size, sizeof(int));
	fill_updated_list(data);
	bfprt_main(data);
}

void	fill_updated_list(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < data->bfprt.oldsize)
	{
		if (data->bfprt.alloc.oldtab[i] < data->bfprt.pivot && data->bfprt.i == 1)
		{
			data->bfprt.alloc.tab[j] = data->bfprt.alloc.oldtab[i];
			data->bfprt.fpivot.tab[j] = data->bfprt.alloc.oldtab[i];
			j++;
		}
		if (data->bfprt.alloc.oldtab[i] > data->bfprt.pivot && data->bfprt.i == 0)
		{
			data->bfprt.alloc.tab[j] = data->bfprt.alloc.oldtab[i];
			data->bfprt.fpivot.tab[j] = data->bfprt.alloc.oldtab[i];
			j++;
		}
		i++;
	}
	free(data->bfprt.alloc.oldtab);
}

void	target_found(t_data *data)
{
	data->medianvalue = data->bfprt.pivot;
	free(data->bfprt.alloc.tab);
	free(data->bfprt.fpivot.tab);
}
