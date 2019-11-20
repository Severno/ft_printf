/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:10:39 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 22:48:45 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void handle_flags(t_param * param, int *iter)
{
	param->str[*iter] == '0' && pf_strchr_flags(param->flags, '0', iter) == 0 ? pf_strcat(param->flags, "0", iter) : 0;
	param->str[*iter] == '#' && pf_strchr_flags(param->flags, '#', iter) == 0 ? pf_strcat(param->flags, "#", iter) : 0;
	param->str[*iter] == '-' && pf_strchr_flags(param->flags, '-', iter) == 0 ? pf_strcat(param->flags, "-", iter) : 0;
	param->str[*iter] == '+' && pf_strchr_flags(param->flags, '+', iter) == 0 ? pf_strcat(param->flags, "+", iter) : 0;
	param->str[*iter] == ' ' && pf_strchr_flags(param->flags, ' ', iter) == 0 ? pf_strcat(param->flags, " ", iter) : 0;
	param->str[*iter] == '\''&& pf_strchr_flags(param->flags, '\'', iter) == 0 ? pf_strcat(param->flags, "\'", iter) : 0;
	param->str[*iter] == '$' && pf_strchr_flags(param->flags, '$', iter) == 0 ? pf_strcat(param->flags, "$", iter) : 0;
	param->str[*iter] == '*' && pf_strchr_flags(param->flags, '*', iter) == 0 ? pf_strcat(param->flags, "*", iter) : 0;
}

static void handle_convension(t_param * param, int *iter)
{
	param->str[*iter] == 'd' ? pf_strcat(param->flags, "d", iter) : 0;
	param->str[*iter] == 'i' ? pf_strcat(param->flags, "i", iter) : 0;
	param->str[*iter] == 'u' ? pf_strcat(param->flags, "u", iter) : 0;
	param->str[*iter] == 'o' ? pf_strcat(param->flags, "o", iter) : 0;
	param->str[*iter] == 'x' ? pf_strcat(param->flags, "x", iter) : 0;
	param->str[*iter] == 'X' ? pf_strcat(param->flags, "X", iter) : 0;
	param->str[*iter] == 'c' ? pf_strcat(param->flags, "c", iter) : 0;
	param->str[*iter] == 's' ? pf_strcat(param->flags, "s", iter) : 0;
	param->str[*iter] == 'p' ? pf_strcat(param->flags, "p", iter) : 0;
	param->str[*iter] == 'f' ? pf_strcat(param->flags, "f", iter) : 0;
	param->str[*iter] == 'L' ? pf_strcat(param->flags, "L", iter) : 0;
	param->str[*iter] == 'h' && param->str[(*iter) + 1] == 'h' ? pf_strcat(param->flags, "hh", iter) : 0;
	param->str[*iter] == 'l' && param->str[(*iter) + 1] == 'l' ? pf_strcat(param->flags, "ll", iter) : 0;
	param->str[*iter] == 'h' ? pf_strcat(param->flags, "h", iter) : 0;
	param->str[*iter] == 'l' ? pf_strcat(param->flags, "l", iter) : 0;
	if (pf_strchr("123456789.", param->str[*iter]))
		flag_width(param, iter);
}


void get_flags(t_param* param)
{
	int iter;
	int size;
	int length;

	iter = param->iter;
	size = 10;
	param->flags = (char*)ft_strnew(size);
	while ((param->current_flag = pf_strchr("diouxXegscpf%", param->str[iter])) == 0)
	{
		handle_convension(param, &iter);
		handle_flags(param, &iter);
		if (param->str[iter] == '\0')
		{
			param->iter = iter;
			return;
		}
	}
	length = ft_strlen(param->flags);
	if (param->str[iter] == '\0')
		return;
	if (pf_strchr("diouxXegscpf%", param->str[iter]))
		param->current_flag = param->str[iter];
	param->flags[length] = (char)param->current_flag;
	if (ft_strstr(param->flags, "Lf"))
		param->ld_value = va_arg(param->args, long double);
	else if (param->current_flag == 'f')
		param->d_value = va_arg(param->args, double);
	else if ((param->current_flag != '%'))
		param->arg_value = va_arg(param->args, void *);
	param->iter = iter;
}

void parse_flag(t_param *param)
{
	if (param->str[param->iter] == '\0')
		return;
	ft_strstr(param->flags, "lld") ? flag_d(param) : 0;
	ft_strstr(param->flags, "ld") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hhd") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hd") ? flag_d(param) : 0;
	ft_strstr(param->flags, "d") ? flag_d(param) : 0;
	ft_strstr(param->flags, "lli") ? flag_d(param) : 0;
	ft_strstr(param->flags, "li") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hhi") ? flag_d(param) : 0;
	ft_strstr(param->flags, "hi") ? flag_d(param) : 0;
	ft_strstr(param->flags, "i") ? flag_d(param) : 0;
	ft_strstr(param->flags, "llu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "lu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "hhu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "hu") ? flag_u(param) : 0;
	ft_strstr(param->flags, "u") ? flag_u(param) : 0;
	ft_strstr(param->flags, "llo") ? flag_o(param) : 0;
	ft_strstr(param->flags, "lo") ? flag_o(param) : 0;
	ft_strstr(param->flags, "hho") ? flag_o(param) : 0;
	ft_strstr(param->flags, "ho") ? flag_o(param) : 0;
	ft_strstr(param->flags, "o") ? flag_o(param) : 0;
	ft_strstr(param->flags, "llx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "lx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hhx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hx") ? flag_x(param) : 0;
	ft_strstr(param->flags, "x") ? flag_x(param) : 0;
	ft_strstr(param->flags, "llX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "lX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hhX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "hX") ? flag_x(param) : 0;
	ft_strstr(param->flags, "X") ? flag_x(param) : 0;
	ft_strstr(param->flags, "c") ? flag_char(param) : 0;
	ft_strstr(param->flags, "s") ? flag_str(param) : 0;
	ft_strstr(param->flags, "p") ? flag_p(param) : 0;
	ft_strstr(param->flags, "Lf") ? flag_f(param, param->ld_value) : 0;
	ft_strstr(param->flags, "f") ? flag_f(param, param->d_value) : 0;
	ft_strstr(param->flags, "%") ? flag_percent(param) : 0;
}
