#include "clean_test_header.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((unsigned char *)dest == NULL && (unsigned char *)src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (((unsigned char *)dest));
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*rep;
// 	size_t	i;

// 	if (nmemb && size > SIZE_MAX / nmemb)
// 		return (NULL);
// 	i = 0;
// 	rep = malloc(nmemb * size);
// 	if (!rep)
// 		return (NULL);
// 	while (i < nmemb * size)
// 		((unsigned char *)rep)[i++] = 0;
// 	return (rep);
// }

