/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:59:16 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 23:34:52 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_d(t_param *param)
{
	char flags[2] = "di";

	param->value = check_convention(param);
	param->val_length = ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	calc_reserved_fields(param);
	get_do_precision(param);
	get_do_width(param);
	print(param);
	remove_current_flags(param, flags);
}

void flag_lld(t_param *param)
{
	char flags[4] = "lldi";

	param->value = check_convention(param);
	param->val_length = (int)ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	calc_reserved_fields(param);
	get_do_precision(param);
	get_do_width(param);
	print(param);
	remove_current_flags(param, flags);
}

void flag_ld(t_param *param)
{
	char flags[3] = "ldi";

	param->value = check_convention(param);
	param->val_length = (int)ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	calc_reserved_fields(param);
	get_do_precision(param);
	get_do_width(param);
	print(param);
	remove_current_flags(param, flags);
}

void flag_hhd(t_param *param)
{
	char flags[4] = "hhdi";

	param->value = check_convention(param);
	param->val_length = (int)ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	calc_reserved_fields(param);
	get_do_precision(param);
	get_do_width(param);
	print(param);
	remove_current_flags(param, flags);
}

void flag_hd(t_param *param)
{
	char flags[3] = "hdi";

	param->value = check_convention(param);
	param->val_length = (int)ft_num_of_fields(param->value);
	param->val_nums = (int)ft_num_of_digits(param->value);
	calc_reserved_fields(param);
	get_do_precision(param);
	get_do_width(param);
	print(param);
	remove_current_flags(param, flags);
}
