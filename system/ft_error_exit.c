#include "libft.h"

void	error_exit(int nb, char *str)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(nb, 2);
	ft_putstr_fd("] : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(nb);
}
