#include "libft.h"

fd -> 0 -> entree standard
fd -> 1 -> sortie standard
fd -> 2 -> sortie erreur

Erro [4] : Can't compile shader
Erro [4] : Bad param given

void	error_exit(int nb, char *str)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(nb, 2);
	ft_putstr_fd("] : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(nb);
}
