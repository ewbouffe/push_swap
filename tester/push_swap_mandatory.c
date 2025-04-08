#include "clean_test_header.h"

void    create_stacks(t_data *data)
{
	t_pile  *pile_a;
	t_pile  *pile_b;

	pile_a = calloc(data->size, sizeof(t_pile));
	pile_b = calloc(data->size, sizeof(t_pile));
	if (!pile_a || !pile_b)
		exit(42);
	
}

void	sa(t_data *data, t_pile **pile_a)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[0];
	*pile_a[0] = *pile_a[1];
	*pile_a[1] = tmp;
}

void	sb(t_data *data, t_pile	**pile_b)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[0];
	*pile_b[0] = *pile_b[1];
	*pile_b[1] = tmp;
}

void	ss(t_data *data, t_pile **pile_a, t_pile **pile_b)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[0];
	*pile_a[0] = *pile_a[1];
	*pile_a[1] = tmp;
	tmp = *pile_b[0];
	*pile_b[0] = *pile_b[1];
	*pile_b[1] = tmp;
}

void	pa(t_data	*data, t_pile **pile_a, t_pile **pile_b)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[0];
	memmove(pile_a + 1, pile_a, data->size);
	*pile_a[0] = tmp;
	memmove(pile_b, pile_b + 1, data->size);
}

void	pb(t_data *data, t_pile **pile_a, t_pile **pile_b)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[0];
	memmove(pile_b + 1, pile_b, data->size);
	*pile_b[0] = tmp;
	memmove(pile_a, pile_a + 1, data->size);
}

void	ra(t_data *data, t_pile **pile_a)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[0];
	memmove(pile_a + 1, pile_a, data->size);
	*pile_a[data->size] = tmp;
}

void	rr_ra(t_data *data, t_pile **pile_a)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[0];
	memmove(pile_a + 1, pile_a, data->size);
	*pile_a[data->size] = tmp;
}

void	rb(t_data *data, t_pile **pile_b)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[0];
	memmove(pile_b + 1, pile_b, data->size);
	*pile_b[data->size] = tmp;
}

void	rr_rb(t_data *data, t_pile **pile_b)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[0];
	memmove(pile_b + 1, pile_b, data->size);
	*pile_b[data->size] = tmp;
}

void	rr(t_data *data, t_pile **pile_a, t_pile **pile_b)
{
	rr_ra(data, pile_a);
	rr_rb(data, pile_b);
}

void	rra(t_data *data, t_pile **pile_a)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[data->size];
	memmove(pile_a, pile_a + 1, data->size);
	*pile_a[0] = tmp;
}

void	rr_rra(t_data *data, t_pile **pile_a)
{
	t_pile tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_a[data->size];
	memmove(pile_a, pile_a + 1, data->size);
	*pile_a[0] = tmp;
}

void	rrb(t_data *data, t_pile **pile_b)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[data->size];
	memmove(pile_b, pile_b + 1, data->size);
	*pile_b[0] = tmp;
}

void	rr_rrb(t_data *data, t_pile **pile_b)
{
	t_pile	tmp;

	ft_memset(&tmp, 0, sizeof(t_pile));
	tmp = *pile_b[data->size];
	memmove(pile_b, pile_b + 1, data->size);
	*pile_b[0] = tmp;
}

void	rrr(t_data *data, t_pile **pile_a, t_pile **pile_b)
{
	rr_rrb(data, pile_b);
	rr_rra(data, pile_a);
}