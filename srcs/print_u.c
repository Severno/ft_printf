#include "../includes/ft_printf.h"

static void zero_handle_u(t_param *param)
{
	if (ftpf_strchr(param->flags, '-'))
	{
		if (param->precision == 0)
		{
			ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			fill_width(param);
		}
		else if (param->precision == -1)
		{
			ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			ft_putunbr(param->un_value);
			fill_width(param);
		}
		else if (param->precision > 0)
		{
			ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
			fill_width(param);
		}
		else
		{
			fill_precision(param);
			ft_putunbr(param->un_value);
			fill_width(param);
		}
	}
	else{
		if (param->precision == 0)
		{
			fill_width(param);
			ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
			fill_precision(param);
		} else if (param->precision == -1)
		{
			if (ftpf_strchr(param->flags, '0'))
			{
				ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_width(param);
				fill_precision(param);
				ft_putunbr(param->un_value);
			} else
			{
				fill_width(param);
				ftpf_strchr(param->flags, '+') ? write(1, "+", 1) : 0;
				fill_precision(param);
				ft_putunbr(param->un_value);
			}
		}
		else if (ftpf_strchr(param->flags, '+'))
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
			if (ftpf_strchr(param->flags, '0') && param->precision == -1 )
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


void print_u(t_param *param)
{
	if (param->un_value == 0)
	{
		zero_handle_u(param);
		return;
	}

	if (ftpf_strchr(param->flags, '-'))
	{
		if (ftpf_strchr(param->flags, '+'))
		{
			write(1, "+", 1);
			fill_precision(param);
			ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
			ft_putunbr(param->un_value);
			fill_width(param);
		}
		else
		{
			fill_precision(param);
			ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
			ft_putunbr(param->un_value);
			fill_width(param);
		}
	}
	else{
		if (ftpf_strchr(param->flags, '+'))
		{
			if (ftpf_strchr(param->flags, '0') && param->precision == -1)
			{
				write(1, "+", 1);
				fill_width(param);
				fill_precision(param);
				ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(param->un_value);
			} else
			{
				fill_width(param);
				write(1, "+", 1);
				fill_precision(param);
				ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(param->un_value);
			}
		}
		else
		{
			if (ftpf_strchr(param->flags, '0') && param->precision == -1 )
			{
				fill_width(param);
				fill_precision(param);
				ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(param->un_value);
			} else{
				fill_width(param);
				fill_precision(param);
				ftpf_strchr(param->flags, '#') != 0 ? write(1, "0", 1) : 0;
				ft_putunbr(param->un_value);
			}
		}
	}
}