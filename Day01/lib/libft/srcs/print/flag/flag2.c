#include "libft.h"

size_t	flag_point(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->point = TRUE;
	return (1);
}

size_t	flag_digit(t_flag_data *data, char *cmd, int i)
{
	char	*actual_cmd;
	int		value;

	actual_cmd = &(cmd[i]);
	value = ft_atoi(actual_cmd);
	if (data->point == FALSE)
		data->padding = value;
	else
	{
		data->precision = value;
		data->zero = FALSE;
	}
	return (nbr_len(value, 10));
}

size_t	flag_wildcard(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == FALSE)
	{
		data->wildcard1 = TRUE;
		data->padding = 0;
	}
	else
	{
		data->wildcard2 = TRUE;
		data->precision = 0;
	}
	return (1);
}

size_t	flag_l(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->l_value++;
	return (1);
}

size_t	flag_h(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->h_value++;
	return (1);
}
