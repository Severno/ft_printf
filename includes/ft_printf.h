/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:56:43 by sapril            #+#    #+#             */
/*   Updated: 2019/11/14 23:18:12 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>


typedef struct s_str_param
{
	long long int			length;
	long long int			precision;
	long long int			field_width;
	char*					str;
}							t_str_param;

typedef struct s_param
{
	long long int			value;
	unsigned long long		un_value;
	int						reserved_fields;
	int						val_length;
	int						val_nums;
	int						iter;
	va_list					args;
	void					*arg_value;
	char					*flags;
	char					*str;
	int						current_flag;
	char					convention;
	int						precision;
	int						width;
	int						do_width;
	int						do_precision;
}							t_param;


// print_d.c
//void print_d(int value, t_param *param);
//void print(t_param *param);
//void left_print(t_param *param);
//void left_negative_print(t_param *param);
//void negative_print(t_param *param);

// ft_printf.c
void						ft_printf(char *input, ...);
long long int				check_convention(t_param *param);
unsigned long long int		check_un_convention(t_param *param);

// flag_precision.c
void						flag_width(t_param *param, int *iter);

// get_flags.c
void						get_flags(t_param* param);
char						*pf_strcat(char *s1, const char *s2, int *iter);
char						ftpf_strchr_flags(const char *s, int c, int *iter);
void						parse_flag(t_param *param);
char						*ft_find_and_remove_char(char *str, char find);
void						remove_conflicted_flags(t_param *param);
void						remove_current_flags(t_param *param, char *flags);

// ftpf_strchr.c
char						ftpf_strchr(const char *s, int c);

// flag_di.c
void						flag_d(t_param *param);
void						flag_lld(t_param *param);
void						flag_ld(t_param *param);
void						flag_hhd(t_param *param);
void						flag_hd(t_param *param);

// flag_o.c
void						flag_o(t_param *param);
void						flag_llo(t_param *param);
void						flag_lo(t_param *param);
void						flag_hho(t_param *param);
void						flag_ho(t_param *param);

// flag_u.c
void						flag_u(t_param *param);
void						flag_llu(t_param *param);
void						flag_lu(t_param *param);
void						flag_hhu(t_param *param);
void						flag_hu(t_param *param);

// flag_x.c
void						flag_x(t_param *param);
void						flag_llx(t_param *param);
void						flag_lx(t_param *param);
void						flag_hhx(t_param *param);
void						flag_hx(t_param *param);

// flag_x.c
void						flag_upx(t_param *param);
void						flag_llupx(t_param *param);
void						flag_lupx(t_param *param);
void						flag_hhupx(t_param *param);
void						flag_hupx(t_param *param);

// flag_cs.c
void						flag_upx(t_param *param);
void						flag_llupx(t_param *param);
void						flag_lupx(t_param *param);
void						flag_hhupx(t_param *param);
void						flag_hupx(t_param *param);

// flag_cs.c
void						flag_str(t_param *param);
void						flag_char(t_param *param);

// alignment.c
void						fill_width(t_param *param);
void						fill_precision(t_param *param);
void						fill(int value, char sign, t_param *param);
void						calc_unreserved_fields(t_param *param);

// utils.c
int							ft_max_of_two(int a,  int b);
int							ft_min_of_two(int a,  int b);
int							ft_max_of_three(int a,  int b,  int c);
int							ft_middle_of_three(int a,  int b,  int c);

// calc_signed_precision.c
void get_do_precision_int(t_param *param, int value);
void get_do_precision_l(t_param *param, long int value);
void get_do_precision_ll(t_param *param, long long int value);
void get_do_precision(t_param *param);

// calc_unsigned_precision.c
void get_do_unprecision(t_param *param);


// calc_signed_width.c
void get_do_width_int(t_param *param, int value);
void get_do_width_l(t_param *param, long int value);
void get_do_width_ll(t_param *param, long long int value);
void get_do_width(t_param *param);
void calc_reserved_fields(t_param *param);
void calc_unreserved_fields(t_param *param);

// calc_unsigned_width.c
void get_do_unwidth(t_param *param);
void calc_unreserved_fields(t_param *param);
int get_base(t_param *param);



// print
//void zero_handle(t_param *param);
void					print_d(t_param *param, int value);
void					print(t_param *param);
void					print_unsigned(t_param *param);

// calc

// pfft_putnbr
void ft_putnbr_base(long long int n, int base);
void ft_putunbr_base(unsigned long long int n, int base);

// print_o.c
void print_o(t_param *param);

// print_u.c
void print_u(t_param *param);


#endif