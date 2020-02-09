#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	result = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
