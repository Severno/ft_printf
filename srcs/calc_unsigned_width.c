#include "../includes/ft_printf.h"

void get_do_unwidth(t_param *param)
{
	if (param->un_value == 0)
	{
		if (pf_strchr(param->flags, '0'))
			param->do_width = param->precision == -1 ? param->width + param->reserved_fields : param->width - param->precision + param->reserved_fields;
		else
			param->do_width = param->precision == -1 ? param->width + param->reserved_fields - param->val_length : param->width - param->precision + param->reserved_fields;
	}
	else if (param->precision >= param->val_length)
	{
		param->do_width = param->width - param->precision + param->reserved_fields;
	} else
		param->do_width = param->width - param->val_length + param->reserved_fields;
}

void calc_unreserved_fields(t_param *param)
{
	int reserved_fields;

	reserved_fields = 0;

	if ((pf_strchr("xX", param->current_flag) != 0))
	{
		pf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		pf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
		if (pf_strchr(param->flags, '#') && param->precision >= -1 && param->un_value > 0)
			reserved_fields -=2;
	} else if (param->current_flag == 'o')
	{
		pf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		pf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
		if (pf_strchr(param->flags, '#') && param->precision <= param->val_length && param->precision == 0 && param->un_value == 0)
			reserved_fields--;
		if (pf_strchr(param->flags, '#') && param->precision <= param->val_length && param->precision >= -1 && param->un_value != 0)
			reserved_fields--;
	} else if (param->current_flag == 'u')
	{
		pf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		pf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
		if (pf_strchr(param->flags, '#') && param->precision <= param->val_length && param->precision == 0 && param->un_value == 0)
			reserved_fields--;
		if (pf_strchr(param->flags, '#') && param->precision <= param->val_length && param->precision >= -1 && param->un_value != 0)
			reserved_fields--;
	}
	param->reserved_fields = reserved_fields;
}

int get_base(t_param *param)
{
	int base;
	base = 10;
	if (pf_strchr(param->flags, 'o'))
		base = 8;
	else if (pf_strchr(param->flags, 'u'))
		base = 10;
	else if (pf_strchr(param->flags, 'x') || pf_strchr(param->flags, 'X'))
		base = 16;
	return base;
}