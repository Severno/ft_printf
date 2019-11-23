/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:24:24 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 18:35:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	round(int precision)
{
	long double rounder;

	rounder = 0.5;
	while (precision)
	{
		rounder /= 10;
		precision--;
	}
	return (rounder);
}

static char			*inf_nan_handle(long double float_num)
{
	if (float_num == -(1.0 / 0.0))
		return ("-inf");
	else if (float_num == (1.0 / 0.0))
		return ("inf");
	else if (float_num != float_num)
		return ("nan");
	return ("");
}

static void			add_exponent(char *res, size_t *i, long long *int_part)
{
	size_t	j;
	size_t	tmp_i;
	char	tmp;

	j = 0;
	tmp_i = *i;
	res[tmp_i - 1] == '-' ? j++ : 0;
	if (*int_part == 0)
		res[(*i)++] = '0';
	else
	{
		while (*int_part)
		{
			res[tmp_i++] = '0' + *int_part % 10;
			*int_part /= 10;
		}
		*i = tmp_i--;
		while (tmp_i > j)
		{
			tmp = res[tmp_i];
			res[(tmp_i)] = res[j];
			res[j++] = tmp;
			tmp_i--;
		}
	}
}

static void			add_mantiss(long double *float_num,
		int *precision, char *res, size_t *i)
{
	char	tmp;
	int		tmp_pres;

	tmp_pres = *precision;
	if (*precision)
	{
		res[(*i)++] = '.';
		while (*precision)
		{
			if (((*precision) == 1)
			&& ((int)(*float_num * 100) % 10) >= 5
			&& ((int)(*float_num * 100) % 10) <= 9
			&& tmp_pres >= 20 && ((int)(*float_num * 10) % 10) >= 2
			&& ((int)(*float_num * 10) % 10) <= 9)
				*float_num += round(*precision);
			*float_num *= 10.0;
			if ((int)(*float_num) == 10)
			{
				res[(*i) - 1] = res[(*i) - 1] + 1;
				*float_num = 0;
			}
			tmp = (char)*float_num;
			res[(*i)++] = '0' + tmp;
			*float_num -= tmp;
			*precision -= 1;
		}
	}
	res[*i] = '\0';
}

char				*ft_ftoa(long double float_num, char *buf,
		int precision, int sign)
{
	long long	int_part;
	size_t		i;

	i = 0;
	if (!ft_strequ(inf_nan_handle(float_num), ""))
		return (inf_nan_handle(float_num));
	if (float_num < 0)
	{
		float_num = -float_num;
		if (sign == 1)
			buf[i++] = '-';
	}
	float_num < 0 ? float_num = -float_num : 0;
	precision > MAX_PRECISION ? precision = MAX_PRECISION : 0;
	precision == -1 ? precision = 6 : 0;
	precision >= 0 ? float_num += round(precision) : 0;
	int_part = (long long)float_num;
	float_num -= (long double)int_part;
	precision > 19 && precision < 53 ? float_num += round(precision) : 0;
	add_exponent(buf, &i, &int_part);
	add_mantiss(&float_num, &precision, buf, &i);
	return (buf);
}
