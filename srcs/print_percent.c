#include "../includes/ft_printf.h"

void print_percent(t_param *param)
{
	if (pf_strchr(param->flags, '-'))
	{
		if (pf_strchr(param->flags, '0'))
		{
			ft_putchar('%');
			fill_width(param);
		} else {
			ft_putchar('%');
			fill_width(param);
		}
	} else{
		if (pf_strchr(param->flags, '0'))
		{
			fill_width(param);
			ft_putchar('%');
		} else {
			fill_width(param);
			ft_putchar('%');
		}
	}
}
