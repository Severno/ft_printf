#include "../includes/ft_printf.h"

static void print_hash_zero(t_param *param, unsigned long long value, char l_case, int *flag)
{
	if (pf_strchr(param->flags, '#') != 0 && *flag == 0)
	{
		if (value > 0)
		{
			if (l_case == 'x')
				ft_putstr("0x");
			else
				ft_putstr("0X");
			*flag = 1;
		}

	}
}

static void zero_handle_x(t_param *param, unsigned long long value, char l_case, int *flag)
{
	if (pf_strchr(param->flags, '-'))
	{
		print_hash_zero(param, value, l_case, flag);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, value, l_case));
		else if (pf_strchr(param->flags, '#') != 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, value, l_case));
		fill_width(param);
	}
	else{
		if (pf_strchr(param->flags, '0'))
		{
			fill_width(param);
			fill_precision(param);
			return;
		}
		print_hash_zero(param, value, l_case, flag);
		fill_width(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, value, l_case));
		else if (pf_strchr(param->flags, '#') != 0 && param->precision < 0)
			ft_putstr(ft_convert_undec_base(16, value, l_case));
	}
}


void print_x(t_param *param, unsigned long long value, char l_case)
{
	int flag;

	flag = 0;
	if (param->un_value == 0)
	{
		zero_handle_x(param, value, l_case, &flag);
		return;
	}
	if (pf_strchr(param->flags, '-'))
	{
		print_hash_zero(param, value, l_case, &flag);
		fill_precision(param);
		ft_putstr(ft_convert_undec_base(16, value, l_case));
		fill_width(param);
	}
	else
	{
		pf_strchr(param->flags, '0') && param->precision == -1 ?
		print_hash_zero(param, value, l_case, &flag) : 0;
		fill_width(param);
		print_hash_zero(param, value, l_case, &flag);
		fill_precision(param);
		ft_putstr(ft_convert_undec_base(16, value, l_case));
	}
}
