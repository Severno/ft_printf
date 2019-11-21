#include "../includes/ft_printf.h"

void print_p(t_param *param, unsigned long long value)
{
	if (pf_strchr(param->flags, '-'))
	{
		ft_putstr("0x");
		fill_precision(param);
		if (value > 0)
			ft_putstr(ft_convert_undec_base(16, value, 'x'));
		else if (value == 0 && param->precision == -1)
			write(1, "0", 1);
		fill_width(param);
	} else{
		fill_width(param);
		ft_putstr("0x");
		fill_precision(param);
		if (value > 0)
			ft_putstr(ft_convert_undec_base(16, value, 'x'));
		else if (value == 0 && param->precision == -1)
			write(1, "0", 1);
	}
}
