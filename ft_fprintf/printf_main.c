/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:59:32 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/06 11:09:21 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
pour epurer le code possibilite de faire une fonction qui recupere l'int convertis en unsigned int en faisant la difference entre UNSIGNED_INT_MAX et la valeur obtenue
 */
int	ft_printf(int fd, const char *str, ...)
{
	char	*buffer;
	va_list	args;
	t_data	data;

	if (!str)
		return (-1);
	data.fd = fd;
	ft_memset(&data, 0, sizeof(t_data));
	va_start(args, str);
	buffer = (char *)ft_calloc(1024, sizeof(char));
	if (!buffer)
		return (0);
	ft_buff_fill(str, buffer, args, &data);
	va_end(args);
	free(buffer);
	return (data.count);
}

char	*ft_buff_fill(char const *str, char *buffer, va_list args, t_data *data)
{
	size_t	j;

	j = 0;
	while (str[j])
	{
		while (str[j] && str[j] != '%' && data->index < 1023)
		{
			buffer[data->index] = str[j];
			data->index++;
			j++;
		}
		if (data->index == 1023)
			printbuffer(buffer, data);
		if (str[j] == '%')
		{
			checkargs(str[j + 1], buffer, args, data);
			j += 2;
		}
	}
	data->count += write(data->fd, buffer, data->index);
	return (buffer);
}

char	*checkargs(char c, char *buffer, va_list args, t_data *data)
{
	if (c == 'X')
		unsignedintcat((unsigned long)va_arg(args, int), buffer,
			"0123456789ABCDEF", data);
	if (c == 'x')
		unsignedintcat((unsigned long)va_arg(args, int), buffer,
			"0123456789abcdef", data);
	if (c == 's')
		printer(buffer, va_arg(args, char *), data);
	if (c == 'd' || c == 'i')
		intcat(va_arg(args, int), buffer, "0123456789", data);
	if (c == '%')
		printer(buffer, "%", data);
	if (c == 'c')
		chartostr((char)va_arg(args, int), buffer, data);
	if (c == 'p')
		ft_addresse((unsigned long long)va_arg(args, void *), buffer,
			"0123456789abcdef", data);
	if (c == 'u')
		intcat((unsigned int)va_arg(args, int), buffer, "0123456789", data);
	return (buffer);
}

char	*printer(char *buffer, char *temp, t_data *data)
{
	size_t	j;

	if (!temp)
		temp = "(null)";
	j = 0;
	while (temp[j])
	{
		while (temp[j] && data->index < 1023)
		{
			buffer[data->index] = temp[j];
			data->index++;
			j++;
		}
		if (data->index == 1023 && temp[j] != '\0')
			printbuffer(buffer, data);
	}
	return (buffer);
}
