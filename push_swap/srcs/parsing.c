/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:22 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/07 10:00:41 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
// NE PAS OUBLIER DE FREE DATA.TAB PLUS TARD DANS LE PROGRAMME
void	main_parsing(char **str, t_data *data)
{
	char	*list;
	
	// 1. verifier que tous les arguments contiennent au moins 1 chiffre 
	check_all_args(str, &data);
	// 2. dans le cas ou tous les arguments sont eligibles les join
	list = ft_merger(str);
	if (!list)
		return ;
	// 3. une fois join ,verifier qu'il n'y a que des chiffre/espaces
	// 4. verifier qu'il n'y a pas d'overflows
	check_list_validity(list, &data);
	// 5. split et atoi les arguments dans un tableau d'ints
	data->tab = array_to_tab(list, &data);
	if (!data->tab)
	{
		free(list);
		return ;
	}
	// 6. verifier qu'il n'y a pas de doublons
	check_doubles(data->tab);
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

int check_list_validity(char *str, t_data *data)
{
	check_char_validity(str, &data);
	check_value_overflow(str, &data);
}

void	check_char_validity(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (48 > str[i] || str[i] > 57)) 
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
		result = multiplication_overflow_checker(10, addition_overflow_checker(result ,str[i], &data, sig), &data, sig);
		i++;
	}
}

int	multiplication_overflow_checker(int multiplier, int nb, t_data *data, int sign)
{
	if (sign * nb * multiplier > INT_MAX || sign * nb * multiplier < INT_MIN)
	{
		data->parsing_error = 1;
		return (0);
	}
	return (multiplier * nb);
}

int	addition_overflow_checker(int nb, char c, t_data *data, int sign)
{
	if (sign *(nb + (c - 48)) > INT_MAX || sign * (nb + (c - 48)) < INT_MIN)
	{
		data->parsing_error = 1;
		return (0);
	}
	return (nb + (c - 48));
}

int	*array_to_tab(char *str, t_data *data)
{
	int	*tab;
	size_t	i;
	char	**newlist;

	data->size = get_list_size(str);
	i = 0;
	tab = malloc(sizeof(int) * data->size);
	if (!tab)
		return ;
	newlist = ft_split((char const)str, ' ');
	if (!newlist)
		return (NULL);
	while (i < data->size)
	{
		tab[i] = ft_atoi((const char)newlist[i]);
		i++;
	}
	return (tab);
}

size_t	get_list_size(char *str)
{
	size_t	i;
	size_t	pass;
	size_t	count;

	count = 0;
	pass = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		pass = 0;
		else if (pass = 0)
		{
			count++;
			pass = 1;
		}
		i++;
	}
	return (count);
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
	while (i < data->size - 1)
	{
		j = i + 1;
		while (data->tab[i] != data->tab[j] && data->tab[j])
			j++;
		if (data->tab[i] == data->tab[j])
			data->parsing_error = 1;
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
	ft_printf(2, "Error\n");
}
