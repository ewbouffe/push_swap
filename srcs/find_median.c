#include "../include/ft_push_swap.h"

void	BFPRT_main(t_data *data)
{
	int **gfive;

	number_of_groups(data);
	gfive = divide_list(data);
	// 0. trouver le nombre de groupes a creer
	// 1. creer les groupes de 5 valeurs -> utiliser data.size
	// 2. trouver la mediane dans ces groupes de 5 valeurs -> faire un algo basique pour trier les liste de 5
	// 3. creer les groupes -> petits/medianes/grands ->
	// 4. faire la mediane des medianes
	// 5. repartir a nouveau dans les groupes
	// 6. determiner dans quel groupe se trouve la mediane globale -> le groupe contenant le plus de valeurs
	// 7. recursive
}

void	number_of_groups(t_data *data)
{
	if (data->size % 5 == 0)
	{
		data->median->groupnumber = data->size / 5;
		data->median->lastgroupsize = 5;
	}
	else
	{
		data->median->groupnumber = data->size / 5 + 1;
		data->median->lastgroupsize = data->size % 5;
	}
}

int	**divide_list(t_data *data)
{
	int	**temp;

	temp = malloc (sizeof(int *) * data->median->groupnumber);
	if (!temp)
		//focntion exit
	if (data->median->lastgroupsize == 5)
	{
		temp = allocate_normal_tabs_round(temp, data);
		temp = fill_tab_round(temp, data);
	}
	else if (data->median->lastgroupsize != 5)
	{
		temp = allocate_normal_tabs_not_round(temp, data); // verification de l'alloc deja geree dans les fonctions appelees-> si echec exit
		temp = fill_tab_not_round(temp, data);
	}
	return (temp);
}

int	**allocate_normal_tabs_round(int **temp, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median->groupnumber)
	{
		temp[i] = malloc (sizeof(int) * 5);
		if (!temp[i])
			// fonction exit
		i++;
	}
	return (temp);
}

int	**allocate_normal_tabs_not_round(int **temp, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->median->groupnumber - 1)
	{
		temp[i] = malloc (sizeof(int) * 5);
		if (!temp[i])
			// fonction exit
		i++;
	}
	temp[i] = malloc (sizeof(int) * data->median->lastgroupsize);
	if (!temp[i])
		// fonction exit
	return (temp);
}

int	**fill_tab_round(int **temp, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (i < data->median->groupnumber)
	{
		j = 0;
		while (j < 5)
		{
			temp[i][j] = data->tab[k];
			j++;
			k++;
		}
		i++;
	}
	return (temp);
}

int	**fill_tab_not_round(int **temp, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (i < data->median->groupnumber - 1)
	{
		j = 0;
		while (j < 5)
		{
			temp[i][j] = data->tab[k];
			j++;
			k++;
		}
		i++;
	}
	temp = fill_last_tab(temp, data, i, k);
	return (temp);
}

int	**fill_last_tab(int **temp, t_data *data, int i, int k)
{
	size_t	j;

	j = 0;
	while (j < data->median->lastgroupsize)
	{
		temp[i][j] = data->tab[k];
		j++;
		k++;
	}
	return (temp)
}