#include "libft.h"

static int	ft_count_str(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static int	ft_str_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
	{
		len++;
	}
	return (len);
}

static char	**ft_tab(char *s, char c, char ***tab)
{
	int	count;

	if (!s)
		return (NULL);
	count = ft_count_str((char *)s, c);
	if (!(*tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	return (*tab);
}

char		**ft_strsplit(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (!ft_tab((char *)s, c, &tab))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = ft_str_len(s, c, i);
			if (!(tab[j] = (char *)ft_memalloc(sizeof(char) * (len + 1))))
				return (NULL);
			ft_strncpy(tab[j], (char *)(s + i), len);
			i = i + len;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
