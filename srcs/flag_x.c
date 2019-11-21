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
	char l_case;

	l_case = param->current_flag == 'X' ? 'X' : 'x';
	param->un_value = check_un_convention(param);
	param->val_length = ft_strlen(ft_convert_undec_base(16, param->un_value, l_case));
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_x(param, param->un_value, l_case);
	remove_current_flags(param, flags);
}
