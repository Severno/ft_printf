/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:49:58 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 23:26:59 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void fill_width(t_param *param)
{
	if (pf_strchr(param->flags, '0') && (param->precision == -1 || param->precision == 0))
		fill(param->do_width, '0', param);
	else
		fill(param->do_width, ' ', param);
}

void fill_float_width(t_param *param, long double value)
{
	if (pf_strchr(param->flags, '0') && is_value(value))
	{
		value <= 0.0 ? write(1, "-",1) : 0;
		fill_float(param->do_width, '0', param);
	}
	else{
		fill_float(param->do_width, ' ', param);
	}
}

void fill_float(int value, char sign, t_param *param)
{
	(void)param;
	while (value > 0) {
		write(1, &sign, 1);
		value--;
	}
}

void fill_precision(t_param *param)
{
	fill(param->do_precision, '0', param);
}

void fill(int value, char sign, t_param *param)
{
	(void)param;
	if (pf_strchr(param->flags, ' '))
	{
		write(1, " ", 1);
		ft_find_and_remove_char(param->flags, ' ');
	}
	while (value > 0) {
		write(1, &sign, 1);
		value--;
	}
}

