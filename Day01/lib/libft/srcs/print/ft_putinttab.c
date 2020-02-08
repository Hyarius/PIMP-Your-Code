#include "libft.h"

void	ft_putinttab(int **tab, int len)
{
	int	j;
	int	i;

	if (tab == NULL)
		error_exit(3, "No int tab to print");
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (j != 0)
				ft_putstr("\t");
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
