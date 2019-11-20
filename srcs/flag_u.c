/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:32:41 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 21:32:52 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_u(t_param *param)
{
	char flags[5] = "llhhu";

	param->un_value = check_un_convention(param);
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_u(param, param->un_value);
	remove_current_flags(param, flags);

}
//
//void flag_llu(t_param *param)
//{
//	char flags[3] = "llu";
//
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_unnum_of_fields(param->un_value);
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_u(param);
//	remove_current_flags(param, flags);
//}
//
//void flag_lu(t_param *param)
//{
//	char flags[2] = "lu";
//
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_unnum_of_fields(param->un_value);
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_u(param);
//	remove_current_flags(param, flags);
//}
//
//void flag_hhu(t_param *param)
//{
//	char flags[3] = "hhu";
//
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_unnum_of_fields(param->un_value);
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_u(param);
//	remove_current_flags(param, flags);
//}
//
//void flag_hu(t_param *param)
//{
//	char flags[2] = "hu";
//
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_unnum_of_fields(param->un_value);
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_u(param);
//	remove_current_flags(param, flags);
//}
