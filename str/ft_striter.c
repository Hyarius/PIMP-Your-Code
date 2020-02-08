#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
