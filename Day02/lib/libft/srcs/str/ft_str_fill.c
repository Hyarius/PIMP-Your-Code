#include "libft.h"

char	*ft_str_fill(char *str, char c, int i)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (str);
}
