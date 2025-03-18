#ifndef TEST_HEADER_H
# define TEST_HEADER_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_median_alloc
{
	// partie de la liste conservee pour la suite
	int	*kept;
	int	**gfive;
	int	*medians;
	int	*tab;
}	t_median_alloc;

typedef struct s_median
{
	// nouvelle taille de la liste
	int	size;
	// nombre de groupes crees pour le bfprt
	size_t	groupnumber;
	// taille du dernier groupe cree pour le bfprt
	size_t	lastgroupsize;
	// pivot trouve a la fin du process
	int	pivot;
	// rang du pivot dans la liste
	int	pivotindex;
	// rang recherche dans la liste -> rang precedent - taille du groupe retire
	int	target;
	struct	s_median_alloc alloc;
}	t_median;

typedef struct s_data
{
	// nombre de valeurs contenues dans la liste donnee en parametres
	int	size;
	// liste de nombre convertie en tableau d'int pour faciliter sa manipulation notamment pour recuperer le pointeur du quicksort
	int	*tab;
	// 0 = la liste donnee en parametre est valide / 1 = la liste donnee en parametre est invalide
	int	parsing_error;
	// valeur de la mediane
	int	medianvalue;
	//structure contenant les groupes de valeurs servants a trouver la mediane dans le BFPRT
	struct s_median	median;
}	t_data;

// fonction mere du parsing, verifie, lance toute les fonctions permettant de verifier la conformite de la liste ansi que de la recuperer en int *tab
void	main_parsing(char **str, t_data *data);
// Fonction qui verifie que tous les arguments de av contiennent au moins 1 chiffre
void	check_all_args(char **str, t_data *data);
// Fonction join qui fusion **av en un tableau simple afin de faciliter sa manipulation par la suite
char	*ft_merger(char **str);
// Fonction helper de merger permettant de connaitre la longueur totale de **av
size_t	total_len(char **str);
// Fonction strcat classique permettant d'ajouter une chaine a la fin d'une autre chaine
char	*ft_strcat(char *s1, char *s2);
// Fonction intermediaire permettant de lancer plusieurs fonctions afin de verifier la conformite de la liste
void check_list_validity(char *str, t_data *data);
// Fonction verifiant que la est composee uniquement de chiffres ou d'espaces, dans le cas contraire data.parsing_error passe a 1
void	check_char_validity(char *str, t_data *data);
// Fonction verifiant que toutes les valeurs de la liste sont comprises entre INT_MAX et INT_MIN, dans le cas contraire data.parsing_error passe a 1
void	check_value_overflow(char *str, t_data *data);
// Fonction helper de check_value_overflow, verifie les overflows par la multiplication
int	multiplication_overflow_checker(int nb, t_data *data, int sign);
// Fonction helper de check_value_overflow, verifie les overflows par l'addition
int	addition_overflow_checker(int nb, char c, t_data *data, int sign);
// Fonction qui converting un array en tableau d'int afin de faciliter les manipulations plus tard
void	array_to_tab(char *str, t_data *data);
// Fonction helper de array_to_tab, permettant de connaitre le nombre de valeurs contenues dans la liste
size_t	get_list_size(char *str);
// Fonction atoi de la libft, transforme un ascii en int
int	ft_atoi(const char *str);
// Fonction permettant de verifier la presence ou non de doublons dans la liste, dans le cas ou il y en aurait data.parsing_error passe a 1
void	check_doubles(t_data *data);
// Fonction permettant d'ecrire le message d'erreur "Error\n" dans la sortie d'erreur grace a un formidable printf
void	print_error(void);
// Fonction strlen de la libft, permet de connaitre la taille d'un array
size_t	ft_strlen(char const *str);
char	**ft_split(const char *s, char c);
void	free_split(char ***dest, size_t i);
void	bfprt_main(t_data *data);
void	find_pivot(t_data *data);
void	init_var(t_data *data);
void	group_init(t_data *data);
void	alloc_tabs(t_data *data);
void	free_tabs(size_t i, t_data *data);
void	fill_tabs(t_data *data);
void	*ft_memset(void *s, int c, size_t n);
void	exiter(t_data *data);
void	get_medians(t_data *data);
void	sort_int_tab(t_data *data);
int	*medians_sorter(int *tab, size_t size);
void	get_median(t_data *data);
void	make_next_list(t_data *data);
void	pivot_index_finder(t_data *data);
void	fill_next_list_btt(t_data *data);
void	fill_next_list_stt(t_data *data);
void	make_new_tab(t_data *data);


# endif