#include "../includes/ft_printf.h"

static void print_hash_zero(t_param *param)
{
	if (pf_strchr(param->flags, '#') != 0 && param->precision <= param->val_length)
		write(1, "0", 1);
}

static void zero_handle_o(t_param *param)
{
	unsigned long long int value;
	value = check_un_convention(param);
	if (pf_strchr(param->flags, '-'))
	{
		if (param->precision == 0)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			print_hash_zero(param);
			fill_width(param);
		}
		else if (param->precision == -1)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			if (pf_strchr(param->flags, '#') == 0)
				ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			print_hash_zero(param);
			fill_width(param);
		}
		else if (param->precision > 0)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			fill_width(param);
		}
		else
		{
			fill_precision(param);
			ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			fill_width(param);
		}
	}
	else{
		if (param->precision == 0)
		{
			fill_width(param);
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			print_hash_zero(param);
			fill_precision(param);
		}
		else if (param->precision == -1)
		{
			if (pf_strchr(param->flags, '0'))
			{
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_width(param);
				fill_precision(param);
//				print_hash_zero(param);
			} else
			{
				fill_width(param);
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_precision(param);
				print_hash_zero(param);
				if (pf_strchr(param->flags, '#') == 0)
					ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			}
		}
		else if (pf_strchr(param->flags, '+'))
		{
			if (param->precision == -1)
			{
				write(1, "+", 1);
				fill_width(param);
				fill_precision(param);
			} else{
				fill_width(param);
				write(1, "+", 1);
				fill_precision(param);
			}
		}
		else if (param->precision > 0)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_width(param);
			fill_precision(param);
			param->do_precision >= 2 ? print_hash_zero(param) : 0;
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1)
			{
				fill_width(param);
				fill_precision(param);
//				print_hash_zero(param);
			}
			else{
				fill_width(param);
				fill_precision(param);
			}
		}
	}
}

void print_o(t_param *param)
{
	if (param->un_value == 0)
	{
		zero_handle_o(param);
		return;
	}

	if (pf_strchr(param->flags, '-'))
	{
		if (pf_strchr(param->flags, '+'))
		{
			write(1, "+", 1);
			fill_precision(param);
			print_hash_zero(param);
			ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			fill_width(param);
		}
		else
		{
			fill_precision(param);
			print_hash_zero(param);
			ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			fill_width(param);
		}
	}
	else{
		if (pf_strchr(param->flags, '+'))
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1)
			{
				write(1, "+", 1);
				fill_width(param);
				fill_precision(param);
				print_hash_zero(param);
				ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			} else
			{
				fill_width(param);
				write(1, "+", 1);
				fill_precision(param);
				print_hash_zero(param);
				ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			}
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				fill_width(param);
				fill_precision(param);
				pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			} else{
				fill_width(param);
				fill_precision(param);
				print_hash_zero(param);
				ft_putstr(ft_convert_undec_base(8, check_un_convention(param), 'x'));
			}
		}
	}
}
