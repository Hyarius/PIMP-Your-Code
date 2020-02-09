#include "libft.h"

void	converter_o(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 8);
	if (flag_data->sharp == TRUE && str[0] != '0')
		ft_str_replace_front("0", &str);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_u(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 10);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_x(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == FALSE && i != 0)
		ft_str_replace_front("0x", &str);
	else if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_x_maj(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == FALSE && i != 0)
		ft_str_replace_front("0X", &str);
	else if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		ft_str_replace_front("0X", &str);
	ft_str_toupper(str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_p(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = va_arg(data->arg, unsigned long long);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->zero == FALSE)
		ft_str_replace_front("0x", &str);
	else if (flag_data->zero == TRUE)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->zero == TRUE)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}
