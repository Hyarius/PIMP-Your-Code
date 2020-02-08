#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t result;

	if (str == NULL)
		return (0);
	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}
