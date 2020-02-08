#include "libft.h"

void	ft_inttab_cpy(int **dest, int **src)
{
	int	i;

	if (src == NULL)
		error_exit(1, "Src is null in ft_inttab_cpy");
	if (dest == NULL)
		error_exit(2, "Dest is null in ft_inttab_cpy");
	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
}
