#include "libft.h"

BOOL			is_only_compose(char *src, char c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int				get_next_line(int fd, char **line)
{
	int			result;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	static char	*saved[10000];

	result = 1;
	while (ft_strcchr(saved[fd], '\n') <= 0)
	{
		result = read(fd, buff, BUFF_SIZE);
		if (result == 0)
			break ;
		buff[result] = '\0';
		if (is_only_compose(buff, '\0', BUFF_SIZE) == TRUE)
		{
			*line = NULL;
			return (0);
		}
		tmp = saved[fd];
		saved[fd] = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (*line != NULL)
		free(*line);
	*line = ft_strcut(&(saved[fd]), '\n');
	return (ft_strlen(*line) + ft_strlen(saved[fd]) + result);
}
