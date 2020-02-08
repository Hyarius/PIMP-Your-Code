#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	char	lastc;
	char	*pstr;

	lastc = (char)c;
	pstr = (char *)str;
	while (*pstr != '\0')
		pstr++;
	while (*pstr != lastc)
	{
		if (pstr == str)
			return (0);
		pstr--;
	}
	return ((char *)pstr);
}
