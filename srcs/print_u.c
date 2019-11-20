#include "../includes/ft_printf.h"

static void zero_handle_u(t_param *param, unsigned long long value)
{
	if (pf_strchr(param->flags, '-'))
	{
		if (param->precision == 0)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			fill_width(param);
		}
		else if (param->precision == -1)
		{
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			ft_putunbr(value);
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
			ft_putunbr(value);
			fill_width(param);
		}
	}
	else{
		if (param->precision == 0)
		{
			fill_width(param);
			pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
		} else if (param->precision == -1)
		{
			if (pf_strchr(param->flags, '0'))
			{
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_width(param);
				fill_precision(param);
//				ft_putunbr(value);
			} else
			{
				fill_width(param);
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_precision(param);
				ft_putunbr(value);
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
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				fill_width(param);
				fill_precision(param);
			}
			else{
				fill_width(param);
				fill_precision(param);
			}
		}
	}
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
		if (pf_strchr(param->flags, '+'))
		{
			write(1, "+", 1);
			fill_precision(param);
			pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
			ft_putunbr(value);
			fill_width(param);
		}
		else
		{
			fill_precision(param);
			pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
			ft_putunbr(value);
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
				pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(value);
			} else
			{
				fill_width(param);
				write(1, "+", 1);
				fill_precision(param);
				pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(value);
			}
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				fill_width(param);
				fill_precision(param);
				pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(value);
			} else{
				fill_width(param);
				fill_precision(param);
				pf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(value);
			}
		}
	}
}