#include "libft.h"

int	ft_min(int nb_number, ...)
{
	int		result;
	int		tmp;
	int		i;
	va_list	params;

	va_start(params, nb_number);
	result = INT_MAX;
	i = 0;
	while (i < nb_number)
	{
		tmp = va_arg(params, int);
		if (tmp < result)
			result = tmp;
		i++;
	}
	va_end(params);
	return (result);
}
