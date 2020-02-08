#include "libft.h"

char	*ft_strcut(char **s1, char delim)
{
	char	*tmp;
	char	*result;
	size_t	len;

	tmp = *s1;
	len = 0;
	while (tmp[len] != '\0' && tmp[len] != delim)
		len++;
	result = ft_strnew(len);
	ft_strncat(result, tmp, len);
	*s1 = ft_strnew(ft_strlen(tmp) - len + 2);
	ft_strcat(*s1, &(tmp[len + 1]));
	free(tmp);
	return (result);
}
