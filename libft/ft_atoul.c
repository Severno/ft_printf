#include "libft.h"

unsigned long long int ft_atoul(const char* str)
{
	unsigned long long int					i;
	uintmax_t								sum_long;

	i = 0;
	sum_long = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		sum_long = sum_long * 10 + (str[i++] - '0');
	return (sum_long);
}