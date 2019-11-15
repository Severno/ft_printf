/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_upx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:33:09 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 21:33:09 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void flag_upx(t_param *param)
{
	unsigned int value;
	value = (unsigned int)param->arg_value;

}

void flag_llupx(t_param *param)
{
	unsigned long long int value;
	value = (unsigned long long int)param->arg_value;

}

void flag_lupx(t_param *param)
{
	unsigned long int value;
	value = (unsigned long int)param->arg_value;

}

void flag_hhupx(t_param *param)
{
	unsigned char value;
	value = (unsigned char)param->arg_value;

}

void flag_hupx(t_param *param)
{
	unsigned short int value;
	value = (unsigned short int)param->arg_value;
}
