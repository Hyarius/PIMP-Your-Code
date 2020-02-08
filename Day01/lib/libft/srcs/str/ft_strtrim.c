#include "libft.h"

char	*ft_strtrim(char *s)
{
	size_t			stop;
	unsigned int	start;
	char			*str;

	if (!s)
		return (NULL);
	start = 0;
	stop = ft_strlen(s) - 1;
	if (stop > 0)
	{
		while (s[stop] == ' ' || s[stop] == '\n' || s[stop] == '\t')
			stop--;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
	}
	stop++;
	if (stop == 1)
	{
		if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
			stop = 0;
	}
	if (stop < start)
		stop = start;
	str = ft_strsub(s, start, stop - start);
	return (str);
}
