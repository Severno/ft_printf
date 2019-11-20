/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:33:29 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 21:33:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_x(t_param *param)
{
	char flags[6] = "llhhxX";
	char letter_case;

	letter_case = param->current_flag == 'X' ? 'X' : 'x';
	param->un_value = check_un_convention(param);
	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), letter_case));
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_x(param);
	remove_current_flags(param, flags);
}
//
//void flag_llx(t_param *param)
//{
//	char flags[4] = "llxX";
//	char letter_case;
//
//	letter_case = param->current_flag == 'X' ? 'X' : 'x';
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), letter_case));
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_x(param);
//	remove_current_flags(param, flags);
//}
//
//void flag_lx(t_param *param)
//{
//	char flags[3] = "lxX";
//	char letter_case;
//
//	letter_case = param->current_flag == 'X' ? 'X' : 'x';
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), letter_case));
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_x(param);
//	remove_current_flags(param, flags);
//
//}
//
//void flag_hhx(t_param *param)
//{
//	char flags[4] = "hhxX";
//	char letter_case;
//
//	letter_case = param->current_flag == 'X' ? 'X' : 'x';
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), letter_case));
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_x(param);
//	remove_current_flags(param, flags);
//
//}
//
//void flag_hx(t_param *param)
//{
//	char flags[3] = "hxX";
//	char letter_case;
//
//	letter_case = param->current_flag == 'X' ? 'X' : 'x';
//	param->un_value = check_un_convention(param);
//	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), letter_case));
//	calc_unreserved_fields(param);
//	get_do_unprecision(param);
//	get_do_unwidth(param);
//	print_x(param);
//	remove_current_flags(param, flags);
//}
