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
	int value;
	char *tmp;

	value = (int)param->arg_value;
	param->val_length = ft_num_of_fields(value);

	if ((ft_strstr(param->flags, "+")) && value < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '+');
		free(tmp);
	}
	ftpf_putnbr(value, param);
}

void flag_lld(t_param *param)
{
	long long int value;

	value = (long long int)param->arg_value;
}

void flag_ld(t_param *param)
{
	long int value;

	value = (long int)param->arg_value;
}

void flag_hhd(t_param *param)
{
	char value;

	value = (char)param->arg_value;
}

void flag_hd(t_param *param)
{
	short value;

	value = (short)param->arg_value;
}


void ftpf_putnbr(int value, t_param *param)
{
	if (value < 0)
	{
		param->do_precision = param->precision - param->val_length + 1;
		fill_width(param);
		write(1, "-", 1);
		fill_precision(param);
		ft_putnbr(value * -1);
	}
	else
	{
		param->do_precision = param->precision - param->val_length;
		fill_precision(param);
		ft_putnbr(value);
		fill_width(param);
	}
}