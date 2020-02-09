#include "libft.h"

int		nbr_len(long long n, int base)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, int base)
{
	static char		*base_str = "0123456789abcdef";
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (base <= 1 || base > 16)
		return (NULL);
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	l = nbr_len(n, base);
	str = ft_strnew(l);
	if (str == NULL)
		return (NULL);
	str[l] = '\0';
	if (n < 0)
		str[0] = '-';
	while (i < l--)
	{
		str[l] = base_str[(n % base)];
		n /= base;
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	return (ft_itoa_base(n, 10));
}
