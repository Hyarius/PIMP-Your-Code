#include "libft.h"

int			ft_tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char		**ft_tab_new(size_t len)
{
	size_t	i;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}

char		**ft_tabdup(char **tab)
{
	size_t	i;
	int		len;
	char	**result;

	len = ft_tab_len(tab);
	result = ft_tab_new(len);
	i = 0;
	while (tab[i] != NULL)
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	return (result);
}
