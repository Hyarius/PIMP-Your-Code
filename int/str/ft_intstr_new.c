#include "libft.h"

int	*ft_int_str_new(int size)
{
	int	i;
	int	*result;

	result = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
