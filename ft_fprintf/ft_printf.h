/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:03:35 by ewbouffe          #+#    #+#             */
/*   Updated: 2025/03/04 09:33:42 by ewbouffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	index;
	int	count;
	int	fd;
}		t_data;
int		nblenbase(long int nbr, int basesize);
int		checkbase(char const *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*printer(char *buffer, char *temp, t_data *data);
char	*intcat(long int nb, char *dest, char const *base, t_data *data);
char	*checkargs(char c, char *buffer, va_list args, t_data *data);
char	*ft_buff_fill(char const *str, char *buffer, va_list args,
			t_data *data);
int		ft_printf(const char *str, ...);
char	*chartostr(char c, char *buffer, t_data *data);
char	*printbuffer(char *buffer, t_data *data);
char	*ft_addresse(unsigned long long int nb, char *dest, char const *base,
			t_data *data);
void	tempinit(char *str, int size);
char	*unsignedintcat(unsigned int nb, char *dest, char const *base,
			t_data *data);
int		unsignednblenbase(unsigned long int nbr, int basesize);
char	*niladresse(char *temp);

#endif