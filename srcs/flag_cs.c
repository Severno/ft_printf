/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:41:11 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 21:41:11 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_str(t_param *param)
{
	char flags[1] = "s";


	param->str_value = param->arg_value != NULL ? (char *)param->arg_value : "(null)";
	param->val_length = ft_strlen((char *)param->arg_value);
	get_do_unprecision(param);
	get_do_unwidth(param);
	ft_putstr((char *)param->arg_value);
	remove_current_flags(param, flags);
}

void flag_char(t_param *param)
{
	char flags[1] = "c";

	param->val_length = 1;
	param->do_width = param->width - param->val_length;
	fill_width(param);
	ft_putchar((char)param->arg_value);
	remove_current_flags(param, flags);
}

