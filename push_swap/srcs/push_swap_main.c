/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:19 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/07 09:17:26 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	*ft_push_swap(int c, char **v)
{
	t_data data;
	
	if (c < 2)
	{
		print_error();
		exit ;
	}
	ft_memset(&data, 0, sizeof(t_data));
	parsing_main(v);
	if (data.parsing_error = 1)
	{
		free(data.tab);
		print_error();
		exit ;
	}
	sorting_algorythm();
}

void	sorting_algorythm()
{
	
}