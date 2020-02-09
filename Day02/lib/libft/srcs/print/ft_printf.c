#include "libft.h"

void	read_cmd(char *cmd, t_data *data)
{
	size_t		i;
	t_flag_data	flag_data;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '%')
		{
			flag_data = create_flag_data();
			i += handle_flag(&flag_data, cmd, i);
			handle_converter(data, &flag_data, cmd, i);
		}
		else
			add_char_to_buffer(data, cmd[i]);
		if (cmd[i] != '\0')
			i++;
	}
}

int		ft_printf(char *cmd, ...)
{
	t_data	data;

	if (cmd == NULL)
		return (-1);
	data = create_data(NULL, 1);
	va_start(data.arg, cmd);
	read_cmd(cmd, &data);
	print_buffer(&data);
	va_end(data.arg);
	return (data.len);
}

int		ft_sprintf(char *s_buffer, char *cmd, ...)
{
	t_data	data;

	if (cmd == NULL || s_buffer == NULL)
		return (-1);
	data = create_data(s_buffer, -1);
	va_start(data.arg, cmd);
	read_cmd(cmd, &data);
	print_buffer(&data);
	va_end(data.arg);
	return (data.len);
}

int		ft_fprintf(int fd, char *cmd, ...)
{
	t_data	data;

	if (cmd == NULL || (fd < 1))
		return (-1);
	data = create_data(NULL, fd);
	va_start(data.arg, cmd);
	read_cmd(cmd, &data);
	print_buffer(&data);
	va_end(data.arg);
	return (data.len);
}
