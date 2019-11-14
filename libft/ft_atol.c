/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:48:16 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 18:16:22 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


long long int ft_atol(const char* str)
{
	long long int					i;
	long long int					sign;
	long long int				sum_long;

	i = 0;
	sign = 1;
	sum_long = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		sum_long = sum_long * 10 + (str[i++] - '0');
	return (sum_long * sign);
}