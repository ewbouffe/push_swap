#include <stdio.h>
#include "test_header.h"
#include <strings.h>

void	*ft_memset(void *s, int c, size_t n);
int	multiplication_overflow_checker(int nb, t_data *data, int sign);
int main(int c, char **v)
{
	(void)c;
	(void)v;
	t_data data;
	char	*joined;
	size_t	i = 0;

	ft_memset(&data, 0, sizeof(t_data));
	if (c < 2)
		data.parsing_error = 1;
	check_all_args(v, &data);
	if (data.parsing_error == 1)
	{
		printf("Error\n");
		return (0);
	}
	joined = ft_merger(v);
	printf("liste merged %s\n", joined);
	array_to_tab(joined, &data);
	while ((int)i < data.size)
	{
		printf("%d\n", data.tab[i]);
		i++;
	}
	check_doubles(&data);
	printf("%d\n", data.parsing_error);
	free(data.tab);
	free(joined);
	return (0);
}

