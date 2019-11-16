#include "../includes/ft_printf.h"

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

static void zero_handle_p(t_param *param)
{
	char letter_case;

	letter_case = param->current_flag == 'X' ? 'X' : 'x';
	if (param->precision == -1)
	{

		if (pf_strchr(param->flags, '-'))
		{
			fill_precision(param);
			write(1, "0", 1);
			fill_width(param);
		} else {
			fill_width(param);
			fill_precision(param);
			if (pf_strchr(param->flags, '0') == 0)
				write(1, "0", 1);
		}
		return;
	}
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
			{
				write(1, "0x", 2);
				ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			}
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
			write(1, "0x", 2);
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
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
				print_hash_zero(param);
			} else
			{
				fill_width(param);
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_precision(param);
				print_hash_zero(param);
				if (pf_strchr(param->flags, '#') == 0)
				{
					write(1, "0x", 2);
					ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
				}
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
			print_hash_zero(param);
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				fill_width(param);
				fill_precision(param);
				print_hash_zero(param);
			}
			else{
				fill_width(param);
				fill_precision(param);
			}
		}
	}
}

void print_p(t_param *param)
{
	char letter_case;

	letter_case = param->current_flag == 'X' ? 'X' : 'x';
	if (param->un_value == 0)
	{
		zero_handle_p(param);
		return;
	}

	if (pf_strchr(param->flags, '-'))
	{
		if (pf_strchr(param->flags, '+'))
		{
			write(1, "+", 1);
			fill_precision(param);
			print_hash_zero(param);
			write(1, "0x", 2);
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			fill_width(param);
		}
		else
		{
			print_hash_zero(param);
			fill_precision(param);
			write(1, "0x", 2);
			ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
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
				write(1, "0x", 2);
				ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			} else
			{
				fill_width(param);
				write(1, "+", 1);
				fill_precision(param);
				print_hash_zero(param);
				write(1, "0x", 2);
				ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			}
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				print_hash_zero(param);
				fill_width(param);
				fill_precision(param);
				write(1, "0x", 2);
				ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			} else{
				fill_width(param);
				print_hash_zero(param);
				fill_precision(param);
				write(1, "0x", 2);
				ft_putstr(ft_convert_undec_base(16, check_un_convention(param), letter_case));
			}
		}
	}
}
