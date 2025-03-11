/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:19 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/09 12:39:18 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_push_swap(int c, char **v)
{
	t_data data;
	
	if (c < 2)
	{
		print_error();
		exit (0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	main_parsing(v, &data);
	if (data.parsing_error == 1)
	{
		free(data.tab);
		print_error();
		exit (0);
	}
	// Parsing valide, peut-etre creer une fonction appelee dans le cas ou data.parsing_error == 1 pour tout free et exit dedans au lieu de free partout etc
	
	// sorting_algorythm();
}

// void	sorting_algorythm()
// {
	
// }

int main(int c, char **v)
{
	ft_push_swap(c ,v);
	return (0);
}