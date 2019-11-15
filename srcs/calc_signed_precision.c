#include "../includes/ft_printf.h"

void get_do_precision(t_param *param)
{
	if (check_convention(param) == 0)
	{
		param->do_precision = param->precision == - 1 ? 0 : param->precision;
	}
	else
	{
		param->do_precision = param->precision - param->val_nums;
	}
}