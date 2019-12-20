#include "../../includes/libft.h"

void		ft_print_sizet_arr(size_t *sizet_arr, int in_line, size_t size)
{
	size_t i;

	i = 0;
	if (in_line == 1)
		while (i < size)
			ft_putunbr(sizet_arr[i++]);
	else if (in_line == 0)
		while (i < size)
		{
			ft_putunbr(sizet_arr[i++]);
			ft_putchar('\n');
		}
}
