#include "../includes/ft_printf.h"

void print_percent(t_param *param)
{
	if (pf_strchr(param->flags, '-'))
	{
		ft_putchar('%');
		fill_width(param);
	} else{
		fill_width(param);
		ft_putchar('%');
	}
}
