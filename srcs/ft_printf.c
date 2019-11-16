/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:26:42 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 22:34:58 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void param_init(t_param *param)
{
//	param->str_value = NULL;
//	param->flags = NULL;
	param->value = 0;
	param->un_value = 0;
	param->reserved_fields = 0;
	param->current_flag = '~';
	param->convention = '~';
	param->arg_value = va_arg(param->args, void *);
	param->width = -1;
	param->precision = -1;
	param->val_length = 0;
	param->val_nums = 0;
	param->do_precision = 0;
	param->do_width = 0;
}

void ft_printf(char *input, ...)
{
	t_param *param;

	param = (t_param*)ft_memalloc(sizeof(t_param));
	param->str = input;
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
			write(1, &param->str[param->iter], 1);
		param->iter++;
	}
	va_end(param->args);
}



//while (ft_isspace(param->str[param->iter]))
//{
//space_counter++;
//param->iter++;
//}
//if (space_counter > 1)
//{
//while (space_counter)
//{
//write(1, " ", 1);
//space_counter--;
//}
//}