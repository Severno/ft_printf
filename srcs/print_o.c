#include "../includes/ft_printf.h"

static void print_hash_zero(t_param *param)
{
	if (pf_strchr(param->flags, '#') != 0 && param->precision <= param->val_length)
		write(1, "0", 1);
}

static void zero_handle_o(t_param *param)
{
	if (pf_strchr(param->flags, '-'))
	{
		pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
		print_hash_zero(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision == -1)
			ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
		fill_width(param);
	}
	else{
		if (pf_strchr(param->flags, '0'))
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_width(param);
			fill_precision(param);
			return;
		}
		fill_width(param);
		pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
		print_hash_zero(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision == -1)
			ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	}
}

void print_o(t_param *param)
{
	if (param->un_value == 0) {
		zero_handle_o(param);
		return;
	}
	if (pf_strchr(param->flags, '-')) {
		if (pf_strchr(param->flags, '+'))
			write(1, "+", 1);
		fill_precision(param);
		print_hash_zero(param);
		ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
		fill_width(param);
	} else {
		if (pf_strchr(param->flags, '+'))
			write(1, "+", 1);
		fill_width(param);
		fill_precision(param);
		print_hash_zero(param);
		ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	}
}
