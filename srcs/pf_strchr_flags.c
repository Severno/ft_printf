#include "../includes/ft_printf.h"

char		pf_strchr_flags(const char *s, int c, int *iter)
{
	char	*ts;
	char	tc;
	size_t	i;

	ts = (char *)s;
	tc = c;
	i = 0;
	while (ts[i] != tc)
	{
		if (!ts[i])
			return (0);
		i++;
	}
	*iter += 1;
	return *(ts + i);
}
