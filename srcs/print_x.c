#include "../includes/ft_printf.h"

static void print_hash_zero(t_param *param)
{
	if (pf_strchr(param->flags, '#') != 0)
	{
		if (param->un_value > 0)
		{
			if (param->current_flag == 'x')
				ft_putstr("0x");
			else if (param->current_flag == 'X')
				ft_putstr("0X");
		}
	}
}

static void zero_handle_x(t_param *param)
{
	char letter_case;

	letter_case = param->current_flag == 'X' ? 'X' : 'x';
	if (pf_strchr(param->flags, '-'))
	{
		print_hash_zero(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
		else if (pf_strchr(param->flags, '#') != 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
		fill_width(param);
	}
	else{
		if (pf_strchr(param->flags, '0'))
		{
			fill_width(param);
			fill_precision(param);
			return;
		}
		print_hash_zero(param);
		fill_width(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
		else if (pf_strchr(param->flags, '#') != 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
	}
}

void print_x(t_param *param)
{
	char letter_case;

	letter_case = param->current_flag == 'X' ? 'X' : 'x';
	if (param->un_value == 0)
	{
		zero_handle_x(param);
		return;
	}
	if (pf_strchr(param->flags, '-')) {
		param->precision > param->val_length ? print_hash_zero(param) : 0;
		fill_precision(param);
		param->precision < param->val_length ? print_hash_zero(param) : 0;
		ft_putstr(ft_convert_undec_base(16, check_un_convention(param), 'x'));
		fill_width(param);
	}
	else
		{
		if (pf_strchr(param->flags, '0'))
		{
			if (param->width > param->precision && param->width > param->val_length)
			{
				print_hash_zero(param);
				fill_width(param);
			}
			else
			{
				fill_width(param);
				print_hash_zero(param);
			}
		}
		else{
			fill_width(param);
			param->precision > param->val_length ? print_hash_zero(param) : 0;
		}
		fill_precision(param);
		param->precision <= param->val_length ? print_hash_zero(param) : 0;
		ft_putstr(ft_convert_undec_base(16, check_un_convention(param), 'x'));
	}
}
