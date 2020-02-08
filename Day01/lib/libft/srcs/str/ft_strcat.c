#include "libft.h"

void	ft_strcat(char *s1, char *s2)
{
	ft_strncat(s1, s2, ft_strlen(s2));
}
