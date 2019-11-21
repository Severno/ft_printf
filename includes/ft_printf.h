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
# include <float.h>


typedef struct s_str_param
{
	long long int			precision;
	char*					str;
}							t_str_param;

typedef struct s_param
{
	long long int			value;
	double					d_value;
	long double				ld_value;
	unsigned long long		un_value;
	int						reserved_fields;
	int						val_length;
	int						val_nums;
	int						iter;
	va_list					args;
	void					*arg_value;
	char					*flags;
	char					*str;
	char					*str_value;
	int						current_flag;
	int						precision;
	int						width;
	int						do_width;
	int						do_precision;
}							t_param;


// ft_printf.c
void						ft_printf(char *input, ...);
long long int				check_convention(t_param *param);
unsigned long long int		check_un_convention(t_param *param);

// flag_precision.c
void						flag_width(t_param *param, int *iter);

// get_flags.c
void						get_flags(t_param* param);
char						*pf_strcat(char *s1, const char *s2, int *iter);
char						pf_strchr_flags(const char *s, int c, int *iter);
void						parse_flag(t_param *param);
char						*ft_find_and_remove_char(char *str, char find);
void						remove_conflicted_flags(t_param *param, long double value);
void						remove_current_flags(t_param *param, char *flags);

// pf_strchr.c
char						pf_strchr(const char *s, int c);

// flag_di.c
void						flag_d(t_param *param);

// flag_o.c
void						flag_o(t_param *param);

// flag_u.c
void						flag_u(t_param *param);

// flag_x.c
void						flag_x(t_param *param);

// flag_cs.c
void						flag_str(t_param *param);
void						flag_char(t_param *param);

// flag_p.c
void flag_p(t_param *param);


// alignment.c
void						fill_width(t_param *param);
void						fill_precision(t_param *param);
void						fill(int value, char sign, t_param *param);
void						fill_float_width(t_param *param, long double value);
void						fill_float(int value, char sign, t_param *param);


// utils.c
int							ft_max_of_two(int a,  int b);
int							ft_min_of_two(int a,  int b);
int							ft_max_of_three(int a,  int b,  int c);
int							ft_middle_of_three(int a,  int b,  int c);

// calc_signed_precision.c
void get_do_precision(t_param *param);

// calc_unsigned_precision.c
void get_do_unprecision(t_param *param, unsigned long long value);


// calc_signed_width.c
void get_do_width(t_param *param, long long int value);
void calc_reserved_fields(t_param *param, long long int value);

// calc_unsigned_width.c
void get_do_unwidth(t_param *param, unsigned long long value);
void calc_unreserved_fields(t_param *param, unsigned long long value);
int get_base(t_param *param);



// print
//void zero_handle(t_param *param);
void					print(t_param *param);

// calc

// pfft_putnbr
void ft_putnbr_base(long long int n, int base);
void ft_putunbr_base(unsigned long long int n, int base);

// print_o.c
void print_o(t_param *param);

// print_u.c
void print_u(t_param *param, unsigned long long value);

// print_x.c
void print_x(t_param *param, unsigned long long value, char l_case);

// print_o.c
void print_p(t_param *param, unsigned long long value);

// flag_percent.c
void flag_percent(t_param *param);

// print_percent.c
void print_percent(t_param *param);

// flag_f.c
void flag_f(t_param *param,long double value);
void flag_lf(t_param *param);

// calc_float_width.c
void calc_do_float_width(t_param *param);
void calc_reserved_float_fields(t_param *param, long double value);

// print_f.c
void print_f(t_param *param, long double value, char *float_val);

// flag_f_handle.c
int			is_nan(long double floatNum);
int			is_inf(long double floatNum);
int			is_value(long double floatNum);

#endif