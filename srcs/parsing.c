/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:22 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/17 16:08:51 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	main_parsing(char **str, t_data *data)
{
	char	*list;
	
	check_all_args(str, data);
	if (data->parsing_error == 1)
		return ;
	list = ft_merger(str);
	if (!list)
		return ;
	check_list_validity(list, data);
	if (data->parsing_error == 1)
	{
		free(list);
		return ;
	}
	array_to_tab(list, data);
	if (!data->tab)
	{
		free(list);
		return ;
	}
	check_doubles(data);
	free(list);
}

void	check_all_args(char **str, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	pass;
	
	i = 1;
	while (str[i])
	{
		j = 0;
		pass = 0;
		while (str[i][j])
		{
			if ('0' <= str[i][j] && str[i][j] <= '9')
				{
					pass = 1;
					j++;
				}
				j++;
		}
		if (pass == 0)
			data->parsing_error = 1;
		i++;
	}
}

char	*ft_merger(char **str)
{
	size_t	i;
	size_t	len;
	char	*joined;
	
	i = 1;
	len = total_len(str);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	ft_memset(joined, 0, len + 1);
	while (str[i])
	{
		while (str[i][0] == 0)
			i++;
		ft_strcat(str[i], joined);
		i++;
	}
	return (joined);
}

char	*ft_strcat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s2[j])
		j++;
	while (s1[i])
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = ' ';
	return (s2);
}

size_t	total_len(char **str)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 1;
	len = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][0] == 0)
			i++;
		while (str[i][j])
		{
			j++;
			len++;
		}
		len++;
		i++;
	}
	return (len);
}

void check_list_validity(char *str, t_data *data)
{
	check_char_validity(str, data);
	if (data->parsing_error == 1)
		return ;
	check_value_overflow(str, data);
}

void	check_char_validity(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (48 > str[i] || str[i] > 57) && str[i] != '-' && str[i] != '+') 
			data->parsing_error = 1;
		i++;
	}
}

void	check_value_overflow(char *str, t_data *data)
{
	int	i;
	int	sig;
	int	result;

	i = 0;
	while (str[i])
	{
		sig = 1;
		result = 0;
		while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sig *= -1;
			i++;
		}
		while ('0' <= str[i] && str[i] <= '9')
		{
			result = multiplication_overflow_checker(result, data, sig);
			result = addition_overflow_checker(result, str[i], data, sig);
			i++;
		}
	}
}

int	multiplication_overflow_checker(int nb, t_data *data, int sign)
{
	if (nb == 0)
		return (0);
	if ((sign == 1 && nb > INT_MAX / 10) || (sign == -1 && -nb < INT_MIN / 10))
	{
		data->parsing_error = 1;
		return (0);
	}
	return (nb * 10);
}

int	addition_overflow_checker(int nb, char c, t_data *data, int sign)
{
	if ((sign == 1 && nb > INT_MAX - (c - 48))|| (sign == -1 && -nb < (INT_MIN + (c - 48))))
	{
		data->parsing_error = 1;
		return (0);
	}
	return (nb + (c - 48));
}

void	array_to_tab(char *str, t_data *data)
{
	size_t	i;
	char	**newlist;

	data->size = get_list_size(str);
	data->median->size = data->size;
	i = 0;
	data->tab = malloc(sizeof(int) * data->size);
	if (!data->tab)
		return ;
	newlist = ft_split((char const *)str, ' ');
	if (!newlist)
		return ;
	while ((int)i < data->size)
	{
		data->tab[i] = ft_atoi((const char *)newlist[i]);
		i++;
	}
	free_split(&newlist, data->size);
}

size_t	get_list_size(char *str)
{
	size_t	i;
	size_t	pass;
	size_t	count;

	count = 0;
	pass = 0;
	i = 0;
	if (str == NULL)
		return (count);
	while (str[i])
	{
		if (str[i] == ' ')
		pass = 0;
		else if (pass == 0)
		{
			count++;
			pass = 1;
		}
		i++;
	}
	return (count);
}

void	free_split(char ***dest, size_t i)
{
	while (i > 0)
	{
		i--;
		free((*dest)[i]);
	}
	free(*dest);
	*dest = NULL;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	int	result;

	i = 0;
	sig = 1;
	result = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	return (result * sig);
}

void	check_doubles(t_data *data)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while ((int)i < data->size - 1)
	{
		j = i + 1;
		while ((int)j < data->size)
		{
			if (data->tab[i] == data->tab[j])
				data->parsing_error = 1;
			j++;
		}
		i++;
	}
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(void)
{
	// ft_printf(2, "Error\n");
	printf("Error\n");
}


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