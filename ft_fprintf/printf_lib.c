/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:59:47 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/04 09:35:04 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*printbuffer(char *buffer, t_data *data)
{
	data->count += write(data->fd, buffer, data->index);
	ft_memset((char *)buffer, 0, 1024);
	data->index = 0;
	return (buffer);
}

int	unsignednblenbase(unsigned long int nbr, int basesize)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / basesize;
		i++;
	}
	return (i);
}

int	nblenbase(long int nbr, int basesize)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / basesize;
		i++;
	}
	return (i);
}
