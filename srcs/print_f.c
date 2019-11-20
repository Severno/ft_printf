#include "../includes/ft_printf.h"

static void handle_zero(t_param *param, long double value, char *float_val)
{
	pf_strchr(param->flags, ' ') && !is_nan(value) && is_inf(value) < 2 && value != -0.0 ? write(1, " ", 1) : 0;
	pf_strchr(param->flags, '+') && value >= 0? write(1, "+",1) : 0;
	fill_float_width(param, value);
	value < 0.0 ? ft_putstr(ft_strchr(float_val, '-') + 1) : ft_putstr(float_val);
	pf_strchr(param->flags, '#') && param->precision == 0 ? write(1, ".", 1) : 0;
	if (param->precision > 53)
		fill(param->precision - 53, '0', param);
}

static void handle_width(t_param *param, long double value, char *float_val)
{
	if (pf_strchr(param->flags, '-') == 0)
		fill_float_width(param, value);
	pf_strchr(param->flags, ' ') && !is_nan(value) && is_inf(value) < 2 && value != -0.0 ? write(1, " ", 1) : 0;
	pf_strchr(param->flags, '+') && value >= 0 ? write(1, "+",1) : 0;
	value < 0.0 ? ft_putstr(ft_strchr(float_val, '-')) : ft_putstr(float_val);
	pf_strchr(param->flags, '#') && param->precision == 0 ? write(1, ".", 1) : 0;
	if (param->precision > 53)
		fill(param->precision - 53, '0', param);
	if (pf_strchr(param->flags, '-') != 0)
		fill_float_width(param, value);
}

static void check_left_condition(t_param *param, long double value, char *float_val)
{
	if (pf_strchr(param->flags, '0'))
		handle_zero(param, value, float_val);
	else
		handle_width(param, value, float_val);
}
static void check_right_condition(t_param *param, long double value, char *float_val)
{
	if (pf_strchr(param->flags, '0'))
		handle_zero(param, value, float_val);
	else
		handle_width(param, value, float_val);
}

void print_f(t_param *param, long double value, char *float_val)
{
	if (pf_strchr(param->flags, '-'))
		check_left_condition(param, value, float_val);
	else
		check_right_condition(param,value, float_val);
}


