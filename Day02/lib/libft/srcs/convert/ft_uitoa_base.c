#include "libft.h"

int		unbr_len(unsigned long long n, int base)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned long long n, int base)
{
	static char		*base_str = "0123456789abcdef";
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (base <= 1 || base > 16)
		return (NULL);
	i = 0;
	l = unbr_len(n, base);
	str = ft_strnew(l);
	if (str == NULL)
		return (NULL);
	str[l] = '\0';
	while (i < l--)
	{
		str[l] = base_str[(n % base)];
		n /= base;
	}
	return (str);
}

char	*ft_uitoa(unsigned long long n)
{
	return (ft_uitoa_base(n, 10));
}
