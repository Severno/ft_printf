/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:29:41 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 21:32:52 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_o(t_param *param)
{
	char flags[1] = "o";

	param->un_value = ft_atoul(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_o(param);
	remove_current_flags(param, flags);
}

void flag_llo(t_param *param)
{
	char flags[3] = "llo";

	param->un_value = ft_atoul(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_o(param);
	remove_current_flags(param, flags);
}

void flag_lo(t_param *param)
{
	char flags[2] = "lo";

	param->un_value = ft_atoul(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_o(param);
	remove_current_flags(param, flags);
}

void flag_hho(t_param *param)
{
	char flags[3] = "hho";

	param->un_value = ft_atoul(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_o(param);
	remove_current_flags(param, flags);
}

void flag_ho(t_param *param)
{
	char flags[2] = "ho";

	param->un_value = ft_atoul(ft_convert_undec_base(8, check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_o(param);
	remove_current_flags(param, flags);
}
