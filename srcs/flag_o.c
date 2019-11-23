/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:29:41 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 18:57:54 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_o(t_param *param)
{
	char *flags;

	flags = ft_strdup("hhllo");
	param->un_value = ft_atoul(ft_convert_undec_base(8,
			check_un_convention(param), 'x'));
	param->val_length = ft_unnum_of_fields(param->un_value);
	calc_unreserved_fields(param, param->un_value);
	get_do_unprecision(param, param->un_value);
	get_do_unwidth(param, param->un_value);
	print_o(param);
	remove_current_flags(param, flags);
	free(flags);
}
