#include "../includes/ft_printf.h"

static void zero_handle(t_param *param)
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
			ft_putnbr_base(param->value, 10);
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
			ft_putnbr_base(param->value, 10);
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
				ft_putnbr_base(param->value, 10);
			} else
			{
				fill_width(param);
				pf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_precision(param);
				ft_putnbr_base(param->value, 10);
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

void print_unsigned(t_param *param)
{
	if (param->value == 0)
	{
		zero_handle(param);
		return;
	}

	if (pf_strchr(param->flags, '-'))
	{
		if (pf_strchr(param->flags, '+'))
		{
			param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
			fill_precision(param);
			param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			fill_width(param);
		}
		else
		{
			param->value < 0 ? write(1, "-", 1) : 0;
			fill_precision(param);
			param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			fill_width(param);
		}
	}
	else{
		if (pf_strchr(param->flags, '+'))
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1)
			{
				param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
				fill_width(param);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			} else
			{
				fill_width(param);
				param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			}
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				param->value < 0 ? write(1, "-", 1) : 0;
				fill_width(param);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			} else{
				fill_width(param);
				param->value < 0 ? write(1, "-", 1) : 0;
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			}
		}
	}
}

void print(t_param *param)
{
	if (param->value == 0)
	{
		zero_handle(param);
		return;
	}

	if (pf_strchr(param->flags, '-'))
	{
		if (pf_strchr(param->flags, '+'))
		{
			param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
			fill_precision(param);
			param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			fill_width(param);
		}
		else
		{
			param->value < 0 ? write(1, "-", 1) : 0;
			fill_precision(param);
			param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			fill_width(param);
		}
	}
	else{
		if (pf_strchr(param->flags, '+'))
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1)
			{
				param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
				fill_width(param);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			} else
			{
				fill_width(param);
				param->value < 0 ? write(1, "-", 1) : write(1, "+", 1);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			}
		}
		else
		{
			if (pf_strchr(param->flags, '0') && param->precision == -1 )
			{
				param->value < 0 ? write(1, "-", 1) : 0;
				fill_width(param);
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			} else{
				fill_width(param);
				param->value < 0 ? write(1, "-", 1) : 0;
				fill_precision(param);
				param->value < 0 ? ft_putunbr_base(param->value * -1, 10) : ft_putnbr_base(param->value, 10);
			}
		}
	}
}