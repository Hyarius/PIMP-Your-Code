#include "libft.h"

void	ft_strncat(char *s1, char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (j < len)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}
