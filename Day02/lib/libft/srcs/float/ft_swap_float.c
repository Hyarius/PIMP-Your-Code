#include "libft.h"

void	ft_swap_float(float *a, float *b)
{
	float tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
