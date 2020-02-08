#include "libft.h"

void					converter_s(t_data *data, t_flag_data *flag_data)
{
	char	*str;
	char	*str2;

	handle_wildcard(data, flag_data);
	str = va_arg(data->arg, char *);
	if (str == NULL)
		str2 = ft_strdup("(null)");
	else
		str2 = ft_strdup(str);
	if ((ft_strlen(str2) > (size_t)(flag_data->precision))
			&& flag_data->point == TRUE)
		str2[(size_t)(flag_data->precision)] = '\0';
	handle_padding(flag_data, &str2);
	add_str_to_buffer(data, str2);
	free(str2);
}

static long long		converter_d_annexe(t_flag_data *flag_data, long long i,
							char **str, BOOL *neg)
{
	if (i < 0)
	{
		flag_data->plus = FALSE;
		(*neg) = TRUE;
		i = -i;
	}
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		(*str) = ft_strnew(1);
	else
		(*str) = ft_itoa(i);
	return (i);
}

void					converter_d(t_data *data, t_flag_data *flag_data)
{
	long long	i;
	BOOL		neg;
	char		*str;

	neg = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh(data, flag_data);
	i = converter_d_annexe(flag_data, i, &str, &neg);
	handle_precision(flag_data, &str);
	if (flag_data->zero == TRUE)
	{
		if (flag_data->plus == TRUE || flag_data->space == TRUE || neg == TRUE)
			flag_data->padding--;
		handle_padding_num(flag_data, &str);
	}
	if (flag_data->space == TRUE && flag_data->plus == FALSE && neg == FALSE)
		ft_str_replace_front(" ", &str);
	if (neg == TRUE && i != LLONG_MIN)
		ft_str_replace_front("-", &str);
	if (flag_data->plus == TRUE)
		ft_str_replace_front("+", &str);
	if (flag_data->zero == FALSE)
		handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void					converter_c(t_data *data, t_flag_data *flag_data)
{
	char	c;
	char	*str;

	str = NULL;
	flag_data->space = FALSE;
	handle_wildcard(data, flag_data);
	c = va_arg(data->arg, int);
	if (c == '\0')
	{
		if (flag_data->padding > 1)
			str = ft_strnew_c(flag_data->padding - 1, ' ');
		if (flag_data->minus == FALSE)
			add_str_to_buffer(data, str);
		add_char_to_buffer(data, '\0');
		if (flag_data->minus == TRUE)
			add_str_to_buffer(data, str);
	}
	else
	{
		str = ft_strnew_c(1, c);
		handle_padding_c(flag_data, &str);
		add_str_to_buffer(data, str);
		free(str);
	}
}

void					converter_i(t_data *data, t_flag_data *flag_data)
{
	converter_d(data, flag_data);
}
