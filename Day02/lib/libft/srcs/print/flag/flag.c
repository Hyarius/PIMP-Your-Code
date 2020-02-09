#include "libft.h"

size_t	flag_sharp(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->sharp = TRUE;
	return (1);
}

size_t	flag_zero(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == FALSE)
		data->zero = TRUE;
	else
		data->precision = 0;
	return (1);
}

size_t	flag_minus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->minus = TRUE;
	data->zero = FALSE;
	return (1);
}

size_t	flag_plus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->plus = TRUE;
	return (1);
}

size_t	flag_space(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->space = TRUE;
	return (1);
}
