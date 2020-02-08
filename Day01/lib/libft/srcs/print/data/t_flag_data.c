#include "libft.h"

t_flag_data	create_flag_data(void)
{
	t_flag_data	result;

	result.sharp = FALSE;
	result.zero = FALSE;
	result.minus = FALSE;
	result.plus = FALSE;
	result.space = FALSE;
	result.point = FALSE;
	result.wildcard1 = FALSE;
	result.wildcard2 = FALSE;
	result.padding = 0;
	result.precision = 0;
	result.l_value = 0;
	result.h_value = 0;
	return (result);
}
