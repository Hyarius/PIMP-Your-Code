#include "libft.h"

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
