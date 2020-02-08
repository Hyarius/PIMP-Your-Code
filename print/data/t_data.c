#include "libft.h"

t_data	create_data(char *s_buffer, int fd)
{
	t_data	result;

	result.len = 0;
	result.fd = fd;
	result.size = 0;
	result.s_buffer = s_buffer;
	return (result);
}

void	print_buffer(t_data *data)
{
	if (data->s_buffer == NULL)
		write(data->fd, data->buffer, data->size);
	else
		ft_target_strncat(data->s_buffer, data->buffer,
			data->len - data->size, data->size);
	data->size = 0;
}

void	add_char_to_buffer(t_data *data, char c)
{
	if (data->size >= PRINTF_BUFFER_SIZE - 1)
		print_buffer(data);
	data->buffer[data->size] = c;
	data->size++;
	data->buffer[data->size] = '\0';
	data->len++;
}

void	add_str_to_buffer(t_data *data, char *str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		add_char_to_buffer(data, str[i]);
		i++;
	}
}

void	add_nb_char_to_buffer(t_data *data, char c, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		add_char_to_buffer(data, c);
		i++;
	}
}
