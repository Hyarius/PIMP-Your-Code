#include "libft.h"

BOOL	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

BOOL	ft_strisprint(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
