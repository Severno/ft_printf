#include "../includes/ft_printf.h"

void float_neg_zero(t_param *param, long double value, char *float_val)
{
//	write(1, "-",1);
//	printf("NEGATIVE\n");
	fill_float_width(param, value);
	ft_putstr(float_val);
	pf_strchr(param->flags, '#') && param->precision == 0 ? write(1, ".", 1) : 0;
	if (param->precision > 53)
		fill(param->precision - 53, '0', param);
}

void float_pos_zero(t_param *param, long double value, char *float_val){
	pf_strchr(param->flags, '+') ? write(1, "+",1) : 0;
	pf_strchr(param->flags, ' ') ? write(1, " ", 1) : 0;
//	printf("POSITIVE\n");
	fill_float_width(param, value);
	ft_putstr(float_val);
	pf_strchr(param->flags, '#') && param->precision == 0 ? write(1, ".", 1) : 0;
	if (param->precision > 53)
		fill(param->precision - 53, '0', param);
}