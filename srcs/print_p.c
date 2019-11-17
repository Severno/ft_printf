#include "../includes/ft_printf.h"

void print_p(t_param *param)
{
	if (pf_strchr(param->flags, '-'))
	{
		ft_putstr("0x");
		ft_putstr(ft_convert_undec_base(16, check_un_convention(param), 'x'));
		fill_width(param);
	} else{
		fill_width(param);
		ft_putstr("0x");
		ft_putstr(ft_convert_undec_base(16, check_un_convention(param), 'x'));
	}

}
