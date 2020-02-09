#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
