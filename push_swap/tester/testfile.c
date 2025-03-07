#include <stdio.h>
#include "../include/ft_push_swap.h"
#include <strings.h>

void	*ft_memset(void *s, int c, size_t n);
int	multiplication_overflow_checker(int nb, t_data *data, int sign);
int main(int c, char **v)
{
	(void)c;
	(void)v;
	t_data data;
	char	*joined;

	ft_memset(&data, 0, sizeof(t_data));
	// if (c < 2)
		// data.parsing_error = 1;
	joined = ft_merger(v);
	printf("liste merged %s\n", joined);
	check_value_overflow(joined, &data);
	printf("0:valide\n1:invalide\nresultat : %d\n", (int)data.parsing_error);
	// multiplication_overflow_checker(214748364, &data, 1);
	// printf("data.parsing_error %d\n", data.parsing_error);
	free(joined);
	return (0);
}

void check_list_validity(char *str, t_data *data)
{
	check_char_validity(str, data);
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
	if ((sign == 1 && nb > INT_MAX / 10) || (sign == -1 && nb < INT_MIN / 10))
	{
		data->parsing_error = 1;
		return (0);
	}
	return (nb * 10);
}

int	addition_overflow_checker(int nb, char c, t_data *data, int sign)
{
	if ((sign == 1 && nb > INT_MAX - (c - 48))|| (sign == -1 && nb < (INT_MIN + (c - 48))))
	{
		data->parsing_error = 1;
		return (0);
	}
	return (nb + (c - 48));
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
