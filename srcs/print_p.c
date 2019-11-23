/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:04:07 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:04:27 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_p(t_param *param, unsigned long long value)
{
	if (param->t_f.minus)
	{
		pf_putstr("0x", param);
		fill_precision(param);
		if (value > 0)
			pf_putstr(ft_convert_undec_base(16, value, 'x'), param);
		else if (value == 0 && param->precision == -1)
			param->bits += write(1, "0", 1);
		fill_width(param);
	}
	else
	{
		fill_width(param);
		pf_putstr("0x", param);
		fill_precision(param);
		if (value > 0)
			pf_putstr(ft_convert_undec_base(16, value, 'x'), param);
		else if (value == 0 && param->precision == -1)
			param->bits += write(1, "0", 1);
	}
}
