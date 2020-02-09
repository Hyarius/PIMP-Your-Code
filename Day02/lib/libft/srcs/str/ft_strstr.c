#include "libft.h"

char	*ft_strstr(char *str, char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!find[0])
		return ((char *)&str[i]);
	while (str[i])
	{
		while (find[j] && (str[i + j] == find[j]))
			j++;
		if (!find[j])
			return ((char *)&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
