#include "libft.h"

char	*ft_strnew_c(size_t len, char c)
{
	char	*result;

	result = ft_strnew(len);
	ft_str_fill(result, c, len);
	return (result);
}
