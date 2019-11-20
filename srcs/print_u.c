#include "../includes/ft_printf.h"

static void print_hash_zero(t_param *param)
{
	if (pf_strchr(param->flags, '#') != 0 && param->precision <= param->val_length)
		write(1, "0", 1);
}

static void zero_handle_u(t_param *param, unsigned long long value)
{
	if (pf_strchr(param->flags, '-'))
	{
		pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
		print_hash_zero(param);
		fill_precision(param);
		if (pf_strchr(param->flags, '#') == 0 && param->precision == -1)
			ft_putunbr(value);
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
		if (pf_strchr(param->flags, '#') == 0 && param->precision == -1)
			ft_putunbr(value);
		fill_precision(param);
	}
}

static void handle_right_condition(t_param *param, unsigned long long value)
{
	if (pf_strchr(param->flags, '0'))
	{
		pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
		fill_width(param);
		fill_precision(param);
		ft_putunbr(value);
		return;
	}
	fill_width(param);
	pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
	print_hash_zero(param);
	fill_precision(param);
	ft_putunbr(value);
}


void print_u(t_param *param, unsigned long long value)
{
	if (value == 0)
	{
		zero_handle_u(param, value);
		return;
	}
	if (pf_strchr(param->flags, '-'))
	{
		pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
		print_hash_zero(param);
		fill_precision(param);
		ft_putunbr(value);
		fill_width(param);
	}
	else
		handle_right_condition(param, value);
}