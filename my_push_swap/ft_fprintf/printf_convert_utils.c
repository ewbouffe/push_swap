/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convert_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:22:43 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/02/28 11:20:06 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chartostr(char c, char *buffer, t_data *data)
{
	char	tmp[2];

	tmp[0] = 0;
	tmp[1] = 0;
	if (c == 0)
	{
		buffer[data->index] = '\0';
		data->index++;
		return (buffer);
	}
	else
		tmp[0] = c;
	printer(buffer, tmp, data);
	return (buffer);
}

char	*ft_addresse(unsigned long long int nb, char *dest, char const *base,
		t_data *data)
{
	int						basesize;
	size_t					size;
	int						start;
	unsigned long long int	n;
	char					temp[24];

	basesize = ft_strlen(base);
	size = unsignednblenbase(nb, basesize);
	tempinit(temp, 24);
	if (!nb)
		niladresse(temp);
	n = nb;
	start = size + 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		temp[start] = (base[n % basesize]);
		n = n / basesize;
		start--;
	}
	if (nb < 0)
		temp[2] = '-';
	printer(dest, temp, data);
	return (dest);
}

char	*unsignedintcat(unsigned int nb, char *dest, char const *base,
		t_data *data)
{
	int					basesize;
	size_t				size;
	int					start;
	unsigned long int	n;
	char				temp[12];

	basesize = ft_strlen(base);
	size = unsignednblenbase(nb, basesize);
	tempinit(temp, 12);
	n = nb;
	start = size - 1;
	if (n == 0)
		temp[start] = '0';
	while (n > 0)
	{
		temp[start] = (base[n % basesize]);
		n = n / basesize;
		start--;
	}
	printer(dest, temp, data);
	return (dest);
}

char	*intcat(long int nb, char *dest, char const *base, t_data *data)
{
	int			basesize;
	size_t		size;
	int			start;
	long int	n;
	char		temp[12];

	basesize = ft_strlen(base);
	size = nblenbase(nb, basesize);
	tempinit(temp, 12);
	n = nb;
	start = size - 1;
	if (n < 0)
		n *= -1;
	if (n == 0)
		temp[start] = '0';
	while (n > 0)
	{
		temp[start] = (base[n % basesize]);
		n = n / basesize;
		start--;
	}
	if (nb < 0)
		temp[0] = '-';
	printer(dest, temp, data);
	return (dest);
}
