/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_mem_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:59:35 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/02/28 11:20:23 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*retour;
	unsigned char	t;

	t = (unsigned char)c;
	retour = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		retour[i] = t;
		i++;
	}
	return (retour);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	if (nmemb == 0)
		return (NULL);
	dest = malloc(nmemb * size);
	if (dest == NULL)
		return (NULL);
	while (i < nmemb * size)
		((unsigned char *)dest)[i++] = 0;
	return (dest);
}

void	tempinit(char *str, int size)
{
	int	i;

	if (size == 12)
	{
		i = 0;
		while (i <= 12)
		{
			str[i] = 0;
			i++;
		}
	}
	else if (size == 24)
	{
		i = 2;
		str[0] = '0';
		str[1] = 'x';
		while (i <= 24)
		{
			str[i] = 0;
			i++;
		}
	}
}

char	*niladresse(char *temp)
{
	temp[0] = '(';
	temp[1] = 'n';
	temp[2] = 'i';
	temp[3] = 'l';
	temp[4] = ')';
	temp[5] = '\0';
	return (temp);
}
