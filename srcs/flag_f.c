/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:11:51 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 19:55:11 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_f(t_param *param, long double value)
{
	char		*flags;
	char		*float_val;

	flags = ft_strdup("Lf");
	float_val = ft_strnew(100);
	float_val = ft_ftoa(value, float_val, param->precision, 1);
	param->val_length = ft_strlen(float_val);
	remove_conflicted_flags(param, value);
	calc_reserved_float_fields(param, value);
	calc_do_float_width(param);
	print_f(param, value, float_val);
	remove_current_flags(param, flags);
	free(flags);
}
