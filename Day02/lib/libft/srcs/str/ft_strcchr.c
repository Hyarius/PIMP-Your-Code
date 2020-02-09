#include "libft.h"

int			ft_strcchr(char *str, char c)
{
	int i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
