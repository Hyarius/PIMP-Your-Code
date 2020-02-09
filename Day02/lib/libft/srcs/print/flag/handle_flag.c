#include "libft.h"

void	create_flag_funct_tab(t_flag_funct *tab)
{
	size_t i;

	i = 0;
	while (i < 128)
		tab[i++] = NULL;
	tab[0] = (void *)1;
	tab['#'] = flag_sharp;
	tab['0'] = flag_zero;
	tab['-'] = flag_minus;
	tab['+'] = flag_plus;
	tab[' '] = flag_space;
	tab['.'] = flag_point;
	tab['1'] = flag_digit;
	tab['2'] = flag_digit;
	tab['3'] = flag_digit;
	tab['4'] = flag_digit;
	tab['5'] = flag_digit;
	tab['6'] = flag_digit;
	tab['7'] = flag_digit;
	tab['8'] = flag_digit;
	tab['9'] = flag_digit;
	tab['l'] = flag_l;
	tab['h'] = flag_h;
	tab['*'] = flag_wildcard;
}

size_t	handle_flag(t_flag_data *data, char *cmd, size_t i)
{
	size_t				j;
	static t_flag_funct	tab[128] = {NULL};

	if (tab[0] == NULL)
		create_flag_funct_tab(tab);
	j = 1;
	while (cmd[i + j] != '\0' && tab[(size_t)(cmd[i + j])] != NULL)
		j += tab[(size_t)(cmd[i + j])](data, cmd, i + j);
	return (j);
}
