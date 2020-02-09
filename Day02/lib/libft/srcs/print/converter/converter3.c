#include "libft.h"

void	converter_percent(t_data *data, t_flag_data *flag_data)
{
	char		*str;

	handle_wildcard(data, flag_data);
	str = ft_strdup("%");
	handle_padding(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_other(t_data *data, t_flag_data *flag_data, char c)
{
	char		str[2];

	(void)flag_data;
	str[0] = c;
	str[1] = '\0';
	add_str_to_buffer(data, str);
}

void	converter_b(t_data *data, t_flag_data *flag_data)
{
	char		*str;
	BOOL		value;
	char		*str2;

	handle_wildcard(data, flag_data);
	value = va_arg(data->arg, int);
	if (value == TRUE)
		str = "true";
	else if (value == FALSE)
		str = "false";
	else
		str = "error";
	str2 = ft_strdup(str);
	if ((ft_strlen(str2) > (size_t)(flag_data->precision))
			&& flag_data->point == TRUE)
		str2[(size_t)(flag_data->precision)] = '\0';
	handle_padding(flag_data, &str2);
	add_str_to_buffer(data, str2);
	free(str2);
}

void	converter_v(t_data *data, t_flag_data *flag_data)
{
	char		*tmp;
	char		*str;
	t_vector2	value;

	(void)flag_data;
	value = va_arg(data->arg, t_vector2);
	str = ft_strdup("(");
	tmp = ft_itoa(value.x);
	ft_str_replace_back(&str, tmp);
	free(tmp);
	ft_str_replace_back(&str, " / ");
	tmp = ft_itoa(value.y);
	ft_str_replace_back(&str, tmp);
	free(tmp);
	ft_str_replace_back(&str, ")");
	add_str_to_buffer(data, str);
	free(str);
}
