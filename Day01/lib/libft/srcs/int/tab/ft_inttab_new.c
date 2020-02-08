#include "libft.h"

int	**ft_inttab_new(int size)
{
	int	i;
	int	**result;

	result = (int **)malloc(sizeof(int *) * (size + 1));
	if (result == NULL)
		error_exit(100, "Can't malloc a int **");
	i = 0;
	while (i < size + 1)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}
