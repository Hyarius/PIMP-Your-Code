#include "libft.h"

void	ft_puttab(char **tab)
{
	int	i;

	if (tab == NULL)
		error_exit(4, "No char tab to print");
	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		i++;
	}
}
