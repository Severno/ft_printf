#include "../includes/ft_printf.h"

void get_do_unprecision(t_param *param)
{
	if (param->un_value == 0)
	{
		param->do_precision = param->precision == - 1 ? 0 : param->precision;
	}
	else
	{
		param->do_precision = param->precision - param->val_length;
	}
}