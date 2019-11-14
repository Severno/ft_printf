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

void get_flags(t_param* param)
{
	int iter;
	int size;

	iter = param->iter;
	size = 10;
	param->flags = (char*)ft_strnew(size);
	while ((param->current_flag = ftpf_strchr("diouxXeg", param->str[iter])) == 0)
	{
		param->str[iter] == 'd' ? pf_strcat(param->flags, "d", &iter) : 0;
		param->str[iter] == 'i' ? pf_strcat(param->flags, "i", &iter) : 0;
		param->str[iter] == 'u' ? pf_strcat(param->flags, "u", &iter) : 0;
		param->str[iter] == 'o' ? pf_strcat(param->flags, "o", &iter) : 0;
		param->str[iter] == 'x' ? pf_strcat(param->flags, "x", &iter) : 0;
		param->str[iter] == 'X' ? pf_strcat(param->flags, "X", &iter) : 0;
		param->str[iter] == 'c' ? pf_strcat(param->flags, "c", &iter) : 0;
		param->str[iter] == 's' ? pf_strcat(param->flags, "s", &iter) : 0;
		param->str[iter] == 'p' ? pf_strcat(param->flags, "p", &iter) : 0;
		param->str[iter] == 'f' ? pf_strcat(param->flags, "f", &iter) : 0;
		param->str[iter] == '0' && ftpf_strchr_flags(param->flags, '0', &iter) == 0 ? pf_strcat(param->flags, "0", &iter) : 0;
		param->str[iter] == '#' && ftpf_strchr_flags(param->flags, '#', &iter) == 0 ? pf_strcat(param->flags, "#", &iter) : 0;
		param->str[iter] == '-' && ftpf_strchr_flags(param->flags, '-', &iter) == 0 ? pf_strcat(param->flags, "-", &iter) : 0;
		param->str[iter] == '+' && ftpf_strchr_flags(param->flags, '+', &iter) == 0 ? pf_strcat(param->flags, "+", &iter) : 0;
		param->str[iter] == ' ' && ftpf_strchr_flags(param->flags, ' ', &iter) == 0 ? pf_strcat(param->flags, " ", &iter) : 0;
		param->str[iter] == '\''&& ftpf_strchr_flags(param->flags, '\'', &iter) == 0 ? pf_strcat(param->flags, "\'", &iter) : 0;
		param->str[iter] == '$' && ftpf_strchr_flags(param->flags, '$', &iter) == 0 ? pf_strcat(param->flags, "$", &iter) : 0;
		param->str[iter] == '*' && ftpf_strchr_flags(param->flags, '*', &iter) == 0 ? pf_strcat(param->flags, "*", &iter) : 0;
		param->str[iter] == 'L' && param->str[iter + 1] == 'f' ? pf_strcat(param->flags, "Lf", &iter) : 0;
		param->str[iter] == 'h' && param->str[iter + 1] == 'h' ? pf_strcat(param->flags, "hh", &iter) : 0;
		param->str[iter] == 'l' && param->str[iter + 1] == 'l' ? pf_strcat(param->flags, "ll", &iter) : 0;
		param->str[iter] == 'h' ? pf_strcat(param->flags, "h", &iter) : 0;
		param->str[iter] == 'l' ? pf_strcat(param->flags, "l", &iter) : 0;
		if (ftpf_strchr("123456789.", param->str[iter]))
			flag_width(param, &iter);
	}
	param->iter = iter;
}

void parse_flag(t_param *param)
{
	param->str[param->iter] == 'd' ? flag_d(param) : 0;
	param->str[param->iter] == 'ld' ? flag_ld(param) : 0;
	param->str[param->iter] == 'lld' ? flag_lld(param) : 0;
	param->str[param->iter] == 'hd' ? flag_hd(param) : 0;
	param->str[param->iter] == 'hhd' ? flag_hhd(param) : 0;
	param->str[param->iter] == 'i' ? flag_d(param) : 0;
	param->str[param->iter] == 'li' ? flag_ld(param) : 0;
	param->str[param->iter] == 'lli' ? flag_lld(param) : 0;
	param->str[param->iter] == 'hi' ? flag_hd(param) : 0;
	param->str[param->iter] == 'hhi' ? flag_hhd(param) : 0;
	param->str[param->iter] == 'u' ? flag_u(param) : 0;
	param->str[param->iter] == 'lu' ? flag_lu(param) : 0;
	param->str[param->iter] == 'llu' ? flag_llu(param) : 0;
	param->str[param->iter] == 'hu' ? flag_hu(param) : 0;
	param->str[param->iter] == 'hhu' ? flag_hhu(param) : 0;
	param->str[param->iter] == 'o' ? flag_o(param) : 0;
	param->str[param->iter] == 'lo' ? flag_lo(param) : 0;
	param->str[param->iter] == 'llo' ? flag_llo(param) : 0;
	param->str[param->iter] == 'ho' ? flag_ho(param) : 0;
	param->str[param->iter] == 'hho' ? flag_hho(param) : 0;
	param->str[param->iter] == 'x' ? flag_x(param) : 0;
	param->str[param->iter] == 'lx' ? flag_lx(param) : 0;
	param->str[param->iter] == 'llx' ? flag_llx(param) : 0;
	param->str[param->iter] == 'hx' ? flag_hx(param) : 0;
	param->str[param->iter] == 'hhx' ? flag_hhx(param) : 0;
	param->str[param->iter] == 'lX' ? flag_lupx(param) : 0;
	param->str[param->iter] == 'llX' ? flag_llupx(param) : 0;
	param->str[param->iter] == 'hX' ? flag_hupx(param) : 0;
	param->str[param->iter] == 'hhX' ? flag_hhupx(param) : 0;
	param->str[param->iter] == 'c' ? flag_char(param) : 0;
	param->str[param->iter] == 's' ? flag_str(param) : 0;
}

void remove_conflicted_flags(t_param *param)
{
	char *tmp;
	if ((ft_strstr(param->flags, "0")) && (ft_strstr(param->flags, "-")))
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '0');
		free(tmp);
	}
	if ((ft_strstr(param->flags, " ")) && (ft_strstr(param->flags, "+")))
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, ' ');
		free(tmp);
	}

}

char *ft_find_and_remove_char(char *str, char find)
{
	size_t i;
	size_t j;
	char *new_str;

	i = 0;
	j = 0;
	if (str == NULL)
		return NULL;
	while (str[i])
	{
		if (str[i] == find)
		{
			j = i;
			while (str[j + 1])
			{
				str[j] = str[j + 1];
				j++;
			}
			str[j] = '\0';
			break;
		}
		i++;
	}
	new_str = ft_strdup(str);
	return new_str;
}

char	*pf_strcat(char *s1, const char *s2, int *iter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i++] = s2[j++];
		*iter += 1;
	}
	s1[i] = '\0';
	return (s1);
}

char		ftpf_strchr_flags(const char *s, int c, int *iter)
{
	char	*ts;
	char	tc;
	size_t	i;

	ts = (char *)s;
	tc = c;
	i = 0;
	while (ts[i] != tc)
	{
		if (!ts[i])
			return (0);
		i++;
	}
	*iter += 1;
	return *(ts + i);
}