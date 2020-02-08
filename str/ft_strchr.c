#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char*)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
