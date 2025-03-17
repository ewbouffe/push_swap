// #include "../include/ft_push_swap.h"
// // bfprt mis en pause, mediane trouvabl de mainiere plus simple, debut du travail sur le quick sort
// void	BFPRT_main(t_data *data)
// {
// 	int **gfive;

// 	number_of_groups(data);
// 	gfive = divide_list(data);
// 	gfive = sort_groups(gfive, data);
// 	init_value_groups(gfive, data);
	
// 	// 0. trouver le nombre de groupes a creer -> fait
// 	// 1. creer les groupes de 5 valeurs -> utiliser data.size -> fait
// 	// 2. trouver la mediane dans ces groupes de 5 valeurs -> faire un algo basique pour trier les liste de 5 -> in progress
// 	// 3. creer les groupes -> petits/medianes/grands ->
// 	// 4. faire la mediane des medianes
// 	// 5. repartir a nouveau dans les groupes
// 	// 6. determiner dans quel groupe se trouve la mediane globale -> le groupe contenant le plus de valeurs
// 	// 7. recursive
// }

// void	number_of_groups(t_data *data)
// {
// 	if (data->size % 5 == 0)
// 	{
// 		data->median->groupnumber = data->size / 5;
// 		data->median->lastgroupsize = 5;
// 	}
// 	else
// 	{
// 		data->median->groupnumber = data->size / 5 + 1;
// 		data->median->lastgroupsize = data->size % 5;
// 	}
// 	data->median->mdsize = data->median->groupnumber;
// 	if (data->median->groupnumber % 2 == 0)
// 		get_groups_size_even(data);
// 	if (data->median->groupnumber % 2 == 1)
// 		get_groups_size_odd(data);
// }

// void	get_groups_size_even(t_data *data)
// {
// 	if (data->median->lastgroupsize % 5 == 3 || data->median->lastgroupsize % 5 == 5) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2 - 1);
// 		data->median->svsize =  2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2);
// 	}
// 	if (data->median->lastgroupsize % 5 == 2 || data->median->lastgroupsize % 5 == 4) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2 - 1) + (data->median->groupnumber / 2 - 1);
// 		data->median->svsize =  2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2);
// 	}
// 	if (data->median->lastgroupsize % 5 == 1) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->groupnumber / 2 - 1);
// 		data->median->svsize = 2 * (data->median->groupnumber - 1) + (data->median->groupnumber / 2);
// 	}
// }

// void	get_groups_size_odd(t_data *data)
// {
// 	if (data->median->lastgroupsize % 5 == 1) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->groupnumber / 2);
// 		data->median->svsize = 2 * (data->median->groupnumber - 1) + (data->median->groupnumber / 2);
// 	}
// 	if (data->median->lastgroupsize % 5 == 2 || data->median->lastgroupsize % 5 == 4) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2 - 1) + (data->median->groupnumber / 2);
// 		data->median->svsize =  2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2);
// 	}
// 	if (data->median->lastgroupsize % 5 == 3 || data->median->lastgroupsize % 5 == 5) 
// 	{
// 		data->median->bigsize = 2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2);
// 		data->median->svsize =  2 * (data->median->groupnumber - 1) + (data->median->lastgroupsize / 2) + (data->median->groupnumber / 2);
// 	}
// }

// int	**divide_list(t_data *data)
// {
// 	int	**temp;

// 	temp = malloc (sizeof(int *) * data->median->groupnumber);
// 	if (!temp)
// 		//focntion exit
// 	if (data->median->lastgroupsize == 5)
// 	{
// 		temp = allocate_normal_tabs_round(temp, data);
// 		temp = fill_tab_round(temp, data);
// 	}
// 	else if (data->median->lastgroupsize != 5)
// 	{
// 		temp = allocate_normal_tabs_not_round(temp, data); // verification de l'alloc deja geree dans les fonctions appelees-> si echec exit
// 		temp = fill_tab_not_round(temp, data);
// 	}
// 	return (temp);
// }

// int	**allocate_normal_tabs_round(int **temp, t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < data->median->groupnumber)
// 	{
// 		temp[i] = malloc (sizeof(int) * 5);
// 		if (!temp[i])
// 			// fonction exit
// 		i++;
// 	}
// 	return (temp);
// }

// int	**allocate_normal_tabs_not_round(int **temp, t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		temp[i] = malloc (sizeof(int) * 5);
// 		if (!temp[i])
// 			// fonction exit
// 		i++;
// 	}
// 	temp[i] = malloc (sizeof(int) * data->median->lastgroupsize);
// 	if (!temp[i])
// 		// fonction exit
// 	return (temp);
// }

// int	**fill_tab_round(int **temp, t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	k = 0;
// 	i = 0;
// 	while (i < data->median->groupnumber)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			temp[i][j] = data->tab[k];
// 			j++;
// 			k++;
// 		}
// 		i++;
// 	}
// 	return (temp);
// }

// int	**fill_tab_not_round(int **temp, t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	k = 0;
// 	i = 0;
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			temp[i][j] = data->tab[k];
// 			j++;
// 			k++;
// 		}
// 		i++;
// 	}
// 	temp = fill_last_tab(temp, data, i, k);
// 	return (temp);
// }

// int	**fill_last_tab(int **temp, t_data *data, int i, int k)
// {
// 	size_t	j;

// 	j = 0;
// 	while (j < data->median->lastgroupsize)
// 	{
// 		temp[i][j] = data->tab[k];
// 		j++;
// 		k++;
// 	}
// 	return (temp);
// }

// int	**sort_groups(int **tab, t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		tab[i] = sort_int_tab(tab[i], data, 5);
// 		i++;
// 	}
// 	tab[i] = sort_int_tab(tab[i], data, data->median->lastgroupsize);
// 	return (tab);
// }

// int	*sort_int_tab(int *tab, t_data *data, int size)
// {
// 	size_t	i;
// 	size_t	j;
// 	int	tmp;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (tab[i] > tab[j])
// 			{
// 				tmp = tab[i];
// 				tab[i] = tab[j];
// 				tab[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (tab);
// }

// void	store_medians(int **tab, t_data *data)
// {
// 	size_t	i;
	
// 	i = 0;
// 	data->median->medianvalues = malloc (sizeof(int) * data->median->mdsize);
// 	if (!data->median->medianvalues)
// 		// fonction exit
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		data->median->medianvalues[i] = tab[i][2];
// 		i++;
// 	}
// 	data->median->medianvalues[i] = tab[i][data->median->lastgroupsize / 2];
// }

// void	store_smallvalues(int **tab, t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	data->median->smallvalues = malloc (sizeof(int) * data->median->svsize);
// 	if (!data->median->smallvalues)
// 		// fonction exit
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		data->median->smallvalues[j] = tab[i][0];
// 		data->median->smallvalues[j + 1] = tab[i][1];
// 		j+=2;
// 		i++;
// 	}
// 	while (k < data->median->lastgroupsize / 2)
// 	{
// 		data->median->smallvalues[j] = tab[i][k];
// 		j++;
// 		k++;
// 	}
// }

// void	store_bigvalues(int **tab, t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	i = 0;
// 	j = 0;
// 	k = data->median->lastgroupsize;
// 	data->median->bigvalues = malloc (sizeof(int) * data->median->bigsize);
// 	if (!data->median->bigvalues)
// 		// fonction exit
// 	while (i < data->median->groupnumber - 1)
// 	{
// 		data->median->bigvalues[j] = tab[i][3];
// 		data->median->bigvalues[j + 1] = tab[i][4];
// 		j+=2;
// 		i++;
// 	}
// 	while (k > data->median->lastgroupsize /2)
// 	{
// 		data->median->bigvalues = tab[i][k];
// 		j++;
// 		k--;
// 	}
// }

// void	init_value_groups(int **tab, t_data *data)
// {
// 	int	mediannumber;

// 	store_bigvalues(tab, data);
// 	store_medians(tab, data);
// 	store_smallvalues(tab, data);
// 	data->median->medianvalues = sort_int_tab(data->median->medianvalues, data, data->median->groupnumber);
// 	sort_median_values(data);
// }

// void	sort_median_values(t_data *data)
// {
// 	size_t	i;
// 	size_t	j;
// 	int	*tmp;

// 	i = 0;
// 	j = data->median->svsize;
// 	tmp = malloc (sizeof(int) * data->median->groupnumber);
// 	if (!tmp)
// 		// fonction exit
// 	tmp = ft_strcpy(tmp, data->median->medianvalues);
// 	while (i < data->median->groupnumber / 2)
// 	{
// 		data->median->smallvalues[j] = tmp[i];
// 		i++;
// 		j++;
// 	}
// 	j = data->median->bigsize;
// 	while (i < data->median->groupnumber)
// 	{
// 		data->median->bigvalues[j] = tmp[i];
// 		i++;
// 		j++;
// 	}
// 	free(data->median->medianvalues);
// }
// // comparer la taille des groupes pour savoir lequel est le plus grand et donc sur lequel lancer la recursive.
// void	select_group(t_data *data)
// {

// }


// void	median_exiter(t_data *data, void *)
// {
// 	if (data->tab || data->median->smallvalues || data->median->medianvalues || data->median->bigvalues)
// 	{	
// 		free_struct(data);
// 		exit(0);
// 	}

// }

// void	free_struct(t_data *data)
// {
// 	if (data->tab)
// 		free(data->tab);
// 	if (data->median->medianvalues)
// 		free(data->median->medianvalues);
// 	if (data->median->bigvalues)
// 		free(data->median->medianvalues);
// 	if (data->median->smallvalues)
// 		free(data->median->medianvalues);
// }