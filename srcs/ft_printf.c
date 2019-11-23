/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:26:42 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 16:19:24 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		param_init(t_param *param)
{
	param->t_f.hash = 0;
	param->t_f.minus = 0;
	param->t_f.zero = 0;
	param->t_f.plus = 0;
	param->t_f.space = 0;
	param->t_f.percent = 0;
	param->value = 0;
	param->d_value = 0;
	param->ld_value = 0;
	param->un_value = 0;
	param->res_fields = 0;
	param->current_flag = '~';
	param->width = -1;
	param->precision = -1;
	param->val_length = 0;
	param->val_nums = 0;
	param->do_precision = 0;
	param->do_width = 0;
	param->float_sign = -1;
}

int				ft_printf(char *input, ...)
{
	t_param *param;

	param = (t_param*)ft_memalloc(sizeof(t_param));
	param->str = input;
	param->iter = 0;
	param->bits = 0;
	va_start(param->args, input);
	while (param->str[param->iter] && (size_t)param->iter < ft_strlen(input))
	{
		if (param->str[param->iter] == '%')
		{
			param_init(param);
			param->iter += 1;
			get_flags(param);
			parse_flag(param);
		}
		else
		{
			write(1, &param->str[param->iter], 1);
			param->bits++;
		}
		param->iter++;
	}
	va_end(param->args);
	return (param->bits);
}
