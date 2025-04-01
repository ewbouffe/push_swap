#include "clean_test_header.h"

void    bfprt_main(t_data *data)
{
	data->bfprt.iteration++;
	if (data->bfprt.iteration == 10)
		exiter(data);
	printf("[%d](bfprt_main)\n", data->bfprt.iteration);
    init_var(data);
    get_pivot(data);
    updated_list_generator(data);
}

void	get_pivot(t_data *data)
{
	data->bfprt.fpivot.counter++;
    data->bfprt.fpivot.tot = calloc(data->bfprt.fpivot.gn, sizeof(int *));
	if (!data->bfprt.fpivot.tot)
		exiter(data);
	group_maker(data);
	group_filler(data);
	medians_extractor(data);
}

void    init_var(t_data *data)
{
	if (data->size == data->bfprt.size)
		data->bfprt.target = data->size / 2;
	if (data->bfprt.size % 5 == 0)
	{
		data->bfprt.gn = data->bfprt.size / 5;
		data->bfprt.fpivot.gn = data->bfprt.gn;
		data->bfprt.lgs = 5;
		data->bfprt.fpivot.lgs = data->bfprt.lgs;
	}
	if (data->bfprt.size % 5 != 0)
	{
		data->bfprt.gn = data->bfprt.size / 5 + 1;
		data->bfprt.fpivot.gn = data->bfprt.gn;
		data->bfprt.lgs = data->bfprt.size % 5;
		data->bfprt.fpivot.lgs = data->bfprt.lgs;
	}
	data->bfprt.pivot = 0;
	data->bfprt.pivotindex = 0;
	printf("[%d](init_var)\n", data->bfprt.iteration);
	printf("[%d](init_var) gn = %zu\n", data->bfprt.iteration, data->bfprt.gn);
	printf("[%d](init_var) lgs = %zu\n", data->bfprt.iteration, data->bfprt.lgs);
	printf("[%d](init_var) target = %d\n", data->bfprt.iteration, data->bfprt.target);
	size_t	i = 0;
	while ((int)i < data->bfprt.size)
	{
		printf("[%d](init_var) tab[%zu]%d\n", data->bfprt.iteration, i, data->bfprt.alloc.tab[i]);
		i++;
	}
	// printf("[%d](init_var)\n", data->bfprt.iteration);
	// printf("[%d](init_var)\n", data->bfprt.iteration);


}

void	updated_list_generator(t_data *data)
{
	if (data->bfprt.pivotindex > data->bfprt.target)
		pivot_is_bigger(data);
	if (data->bfprt.pivotindex < data->bfprt.target)
		pivot_is_smaller(data);
	if (data->bfprt.pivotindex == data->bfprt.target)
		target_found(data);
}

