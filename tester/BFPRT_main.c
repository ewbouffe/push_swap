#include "clean_test_header.h"

void    bfprt_main(t_data *data)
{
    init_var(data);
    get_pivot(data);
    // updated_list_generator(data);
}

void	get_pivot(t_data *data)
{
		printf("[%d](medians_extractor) fpivot.gn = %zu\n[%d](medians_extractor) fpivot.lgs = %zu\n", data->bfprt.iteration, data->bfprt.fpivot.gn, data->bfprt.iteration, data->bfprt.fpivot.lgs);
	data->bfprt.iteration++;
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
		data->bfprt.lgs = data->bfprt.gn % 5;
		data->bfprt.fpivot.lgs = data->bfprt.lgs;
	}
	data->bfprt.pivot = 0;
	data->bfprt.pivotindex = 0;
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

