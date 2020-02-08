#include "libft.h"

BOOL	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}

BOOL	ft_strisalnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
