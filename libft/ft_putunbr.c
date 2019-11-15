#include "libft.h"

void	ft_putunbr(unsigned long long int nb)
{
	if (nb / 10 != 0)
		ft_putunbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
