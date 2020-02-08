#include "libft.h"

BOOL	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (FALSE);
	return (TRUE);
}

BOOL	ft_strisdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
