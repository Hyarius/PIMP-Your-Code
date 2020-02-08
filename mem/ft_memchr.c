#include "libft.h"

void	*ft_memchr(void *str, int c, size_t len)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char *)str;
	while (i < len)
	{
		if (tab[i] == (unsigned char)c)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
