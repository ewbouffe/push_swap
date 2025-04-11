#include "clean_test_header.h"

int	main(int c, char **v)
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
	pile_init_main(data);
	sort_algo_main(data);
}
