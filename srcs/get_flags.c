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
	int length;

	iter = param->iter;
	size = 10;
	param->flags = (char*)ft_strnew(size);
	while ((param->current_flag = pf_strchr("diouxXegsc", param->str[iter])) == 0)
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
		param->str[iter] == '0' && pf_strchr_flags(param->flags, '0', &iter) == 0 ? pf_strcat(param->flags, "0", &iter) : 0;
		param->str[iter] == '#' && pf_strchr_flags(param->flags, '#', &iter) == 0 ? pf_strcat(param->flags, "#", &iter) : 0;
		param->str[iter] == '-' && pf_strchr_flags(param->flags, '-', &iter) == 0 ? pf_strcat(param->flags, "-", &iter) : 0;
		param->str[iter] == '+' && pf_strchr_flags(param->flags, '+', &iter) == 0 ? pf_strcat(param->flags, "+", &iter) : 0;
		param->str[iter] == ' ' && pf_strchr_flags(param->flags, ' ', &iter) == 0 ? pf_strcat(param->flags, " ", &iter) : 0;
		param->str[iter] == '\''&& pf_strchr_flags(param->flags, '\'', &iter) == 0 ? pf_strcat(param->flags, "\'", &iter) : 0;
		param->str[iter] == '$' && pf_strchr_flags(param->flags, '$', &iter) == 0 ? pf_strcat(param->flags, "$", &iter) : 0;
		param->str[iter] == '*' && pf_strchr_flags(param->flags, '*', &iter) == 0 ? pf_strcat(param->flags, "*", &iter) : 0;
		param->str[iter] == 'L' && param->str[iter + 1] == 'f' ? pf_strcat(param->flags, "Lf", &iter) : 0;
		param->str[iter] == 'h' && param->str[iter + 1] == 'h' ? pf_strcat(param->flags, "hh", &iter) : 0;
		param->str[iter] == 'l' && param->str[iter + 1] == 'l' ? pf_strcat(param->flags, "ll", &iter) : 0;
		param->str[iter] == 'h' ? pf_strcat(param->flags, "h", &iter) : 0;
		param->str[iter] == 'l' ? pf_strcat(param->flags, "l", &iter) : 0;
		if (pf_strchr("123456789.", param->str[iter]))
			flag_width(param, &iter);
	}
	length = ft_strlen(param->flags);
	param->flags[length] = (char)param->current_flag;
	remove_conflicted_flags(param);
	param->iter = iter;
}

void parse_flag(t_param *param)
{
	ft_strstr(param->flags, "lld") ? flag_lld(param) : 0;
	ft_strstr(param->flags, "ld") ? flag_ld(param) : 0;
	ft_strstr(param->flags, "hhd") ? flag_hhd(param) : 0;
	ft_strstr(param->flags, "hd") ? flag_hd(param) : 0;
	ft_strstr(param->flags, "d") ? flag_d(param) : 0;
	ft_strstr(param->flags, "lli") ? flag_lld(param) : 0;
	ft_strstr(param->flags, "li") ? flag_ld(param) : 0;
	ft_strstr(param->flags, "hhi") ? flag_hhd(param) : 0;
	ft_strstr(param->flags, "hi") ? flag_hd(param) : 0;
	ft_strstr(param->flags, "i") ? flag_d(param) : 0;
	ft_strstr(param->flags, "llu") ? flag_llu(param) : 0;
	ft_strstr(param->flags, "lu") ? flag_lu(param) : 0;
	ft_strstr(param->flags, "hhu") ? flag_hhu(param) : 0;
	ft_strstr(param->flags, "hu") ? flag_hu(param) : 0;
	ft_strstr(param->flags, "u") ? flag_u(param) : 0;
	ft_strstr(param->flags, "llo") ? flag_llo(param) : 0;
	ft_strstr(param->flags, "lo") ? flag_lo(param) : 0;
	ft_strstr(param->flags, "hho") ? flag_hho(param) : 0;
	ft_strstr(param->flags, "ho") ? flag_ho(param) : 0;
	ft_strstr(param->flags, "o") ? flag_o(param) : 0;
	ft_strstr(param->flags, "llx") ? flag_llx(param) : 0;
	ft_strstr(param->flags, "lx") ? flag_lx(param) : 0;
	ft_strstr(param->flags, "hhx") ? flag_hhx(param) : 0;
	ft_strstr(param->flags, "hx") ? flag_hx(param) : 0;
	ft_strstr(param->flags, "x") ? flag_x(param) : 0;
	ft_strstr(param->flags, "llX") ? flag_llx(param) : 0;
	ft_strstr(param->flags, "lX") ? flag_lx(param) : 0;
	ft_strstr(param->flags, "hhX") ? flag_hhx(param) : 0;
	ft_strstr(param->flags, "hX") ? flag_hx(param) : 0;
	ft_strstr(param->flags, "X") ? flag_x(param) : 0;
	ft_strstr(param->flags, "c") ? flag_char(param) : 0;
	ft_strstr(param->flags, "s") ? flag_str(param) : 0;
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
	if ((ft_strstr(param->flags, " ")) && check_convention(param) < 0)
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, ' ');
		free(tmp);
	}
}

void remove_current_flags(t_param *param, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		ft_find_and_remove_char(param->flags, flags[i]);
		i++;
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

char		pf_strchr_flags(const char *s, int c, int *iter)
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