#include "clean_test_header.h"

void    pile_init_main(t_data *data)
{
    get_limits(data);
    create_stacks(data);
}
void	create_stacks(t_data *data)
{
	size_t	i;

	data->pile_a = calloc(data->size, sizeof(t_pile));
	data->pile_b = calloc(data->size, sizeof(t_pile));
	if (!data->pile_a || !data->pile_b)
		exit(42);
		i = 0;
	while (i < data->size)
	{
		data->pile_a[i].value = data->tab[i];
		data->pile_a[i].part = get_decile(data, data->tab[i]);
		i++;
	}
}

void	get_limits(t_data *data)
{
	if (data->size > 100)
		morethanhundred(data);
	if (data->size <= 100)
		lessthanhundred(data);
}

void	morethanhundred(t_data *data)
{
	size_t	j;

	data->cln = data->size / 30;
	if (data->size % 30 != 0)
		data->cln = data->size / 30 + 1;
	data->cl = calloc(sizeof(int) , data->cln);
	if (!data->cl)
		//fonction exit
	j = 0;
	while (j < data->cln)
	{
		data->cl[j] = bfprt_main(data, j * 30); // j * 30 = data.target ->> modifier la structure de bfprt main
		j++;
	}
}

void	lessthanhundred(t_data *data)
{
	size_t	j;

	data->cln = data->size / 10;
	if (data->size % 10 != 0)
		data->cln = data->size / 10 + 1;
	data->cl = calloc(sizeof(int) , data->cln);
	if (!data->cl)
		// fonction exit
	j = 0;
	while (j < data->cln)
	{
		data->cl[j] = bfprt_main(data, j * 10);
		j++;
	}
}

int	get_decile(t_data *data, int nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (nb > data->cl[j] && j < data->cln)
		i++;
	return (i);
}
