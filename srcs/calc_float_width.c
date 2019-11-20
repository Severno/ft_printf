#include "../includes/ft_printf.h"

int calc_num_of_float_fields(long double num, int precision)
{
	long long expPart;
	int counter;

	counter = 1;
	expPart = (long long)num;
	if (precision == 0)
		return (ft_num_of_fields((long long int)num));
	else if (precision == -1)
	{
		while (expPart /= 10)
			counter++;
		return counter + 1 + 6;
	}
	else
	{
		while (expPart /= 10)
			counter++;
		while (precision)
		{
			counter++;
			precision--;
		}
		if (num < 0)
			counter++;
		return counter + 1;
	}
}

void calc_reserved_float_fields(t_param *param,long double value)
{
	int reserved_fields;
	char *tmp;

	reserved_fields = 0;

	if ((ft_strstr(param->flags, "+")) && value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		free(tmp);
	}
	if (value >= 0)
	{
		pf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		pf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
	}
	if (pf_strchr(param->flags, '#') && param->precision == 0)
		reserved_fields--;
	param->reserved_fields = reserved_fields;
}


void calc_reserved_lfloat_fields(t_param *param)
{
	int reserved_fields;
	char *tmp;

	reserved_fields = 0;

	if ((ft_strstr(param->flags, "+")) && param->ld_value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		free(tmp);
	}
	if (param->ld_value >= 0)
	{
		pf_strchr(param->flags, '+') ? reserved_fields-- : 0;
		pf_strchr(param->flags, ' ') ? reserved_fields-- : 0;
	}
	if (pf_strchr(param->flags, '#') && param->precision == 0)
		reserved_fields--;
	param->reserved_fields = reserved_fields;
}


void calc_do_float_width(t_param *param)
{
	param->do_width = param->width - param->val_length + param->reserved_fields;
}