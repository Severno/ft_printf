/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:41:18 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 10:46:47 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_print_str_arr(char *arr, int in_line)
{
	int i;

	i = 0;
	if (in_line == 1)
		ft_putstr(arr);
	else if (in_line == 0)
	{
		ft_putstr(arr);
		ft_putchar('\n');
	}
}