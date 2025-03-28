#include "clean_test_header.h"

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


void	free_tot(size_t i, t_data *data)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(data->bfprt.fpivot.tot[j]);
		j++;
	}
	free(data->bfprt.fpivot.tot);
	data->bfprt.fpivot.tot = NULL;
}

void	exiter(t_data *data)
{
	if (data->tab)
		free(data->tab);
	if (data->bfprt.fpivot.tot)
		free_tot(data->bfprt.fpivot.gn, data);
	if (data->bfprt.fpivot.medians)
		free(data->bfprt.fpivot.medians);
	if (data->bfprt.fpivot.tab)
		free(data->bfprt.fpivot.tab);
	if (data->bfprt.alloc.oldtab)
		free(data->bfprt.alloc.oldtab);
	if (data->bfprt.alloc.tab)
		free(data->bfprt.alloc.tab);
}

