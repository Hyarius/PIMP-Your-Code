#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
