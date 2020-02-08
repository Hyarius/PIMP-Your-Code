#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = s;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
