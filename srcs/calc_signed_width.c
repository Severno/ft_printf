#include "../includes/ft_printf.h"

void get_do_width(t_param *param)
{
	long long int value;

	value = check_convention(param);
	if (value == 0)
	{
		param->do_width = param->precision == -1 ? param->width + param->reserved_fields - param->val_nums : param->width - param->precision + param->reserved_fields;
	}
	else if (param->precision >= param->val_nums)
	{
		if (value < 0)
			param->do_width = param->width - param->precision + param->reserved_fields;
		else
			param->do_width = param->width - param->precision + param->reserved_fields;
	} else
		param->do_width = param->width - param->val_nums + param->reserved_fields;
}

void calc_reserved_fields(t_param *param)
{
	long long int value;
	int reserved_fields;
	char *tmp;

	value = check_convention(param);
	reserved_fields = 0;

	if ((ft_strstr(param->flags, "+")) && value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		free(tmp);
	}
	if (value >= 0)
	{
		ftpf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		ftpf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
	} else
	{
		value < 0 ? reserved_fields -= 1 : 0;
	}
	param->reserved_fields = reserved_fields;
}
