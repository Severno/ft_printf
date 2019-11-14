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
	if (param->width > param->precision && param->width > param->val_length)
		param->do_width = param->width - ft_max_of_two(param->precision, param->val_length);
	fill(param->do_width, ' ');
}

void fill_precision(t_param *param)
{
	fill(param->do_precision, '0');
}

void fill(int value, char sign)
{
	while (value > 0) {
		write(1, &sign, 1);
		value--;
	}
}