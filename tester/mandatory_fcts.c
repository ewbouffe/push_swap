#include "clean_test_header.h"

void	sa(t_data *data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[0];
	data->pile_a[0] = data->pile_a[1];
	data->pile_a[1] = tmp;
}

void	sb(t_data *data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[0];
	data->pile_b[0] = data->pile_b[1];
	data->pile_b[1] = tmp;
}

void	ss(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[0];
	data->pile_a[0] = data->pile_a[1];
	data->pile_a[1] = tmp;
	tmp = data->pile_b[0];
	data->pile_b[0] = data->pile_b[1];
	data->pile_b[1] = tmp;
}

void	pa(t_data	*data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[0];
	memmove(data->pile_a + 1, data->pile_a, data->size);
	data->pile_a[0] = tmp;
	memmove(data->pile_b, data->pile_b + 1, data->size);
}

void	pb(t_data *data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[0];
	memmove(data->pile_b + 1, data->pile_b, data->size);
	data->pile_b[0] = tmp;
	memmove(data->pile_a, data->pile_a + 1, data->size);
}

void	ra(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[0];
	memmove(data->pile_a + 1, data->pile_a, data->size);
	data->pile_a[data->size] = tmp;
}

void	rr_ra(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[0];
	memmove(data->pile_a + 1, data->pile_a, data->size);
	data->pile_a[data->size] = tmp;
}

void	rb(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[0];
	memmove(data->pile_b + 1, data->pile_b, data->size);
	data->pile_b[data->size] = tmp;
}

void	rr_rb(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[0];
	memmove(data->pile_b + 1, data->pile_b, data->size);
	data->pile_b[data->size] = tmp;
}

void	rr(t_data *data)
{
	rr_ra(data);
	rr_rb(data);
}

void	rra(t_data *data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[data->size];
	memmove(data->pile_a, data->pile_a + 1, data->size);
	data->pile_a[0] = tmp;
}

void	rr_rra(t_data *data)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_a[data->size];
	memmove(data->pile_a, data->pile_a + 1, data->size);
	data->pile_a[0] = tmp;
}

void	rrb(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[data->size];
	memmove(data->pile_b, data->pile_b + 1, data->size);
	data->pile_b[0] = tmp;
}

void	rr_rrb(t_data *data)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = data->pile_b[data->size];
	memmove(data->pile_b, data->pile_b + 1, data->size);
	data->pile_b[0] = tmp;
}

void	rrr(t_data *data)
{
	rr_rrb(data);
	rr_rra(data);
}