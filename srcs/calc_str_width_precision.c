//
//#include "../includes/ft_printf.h"
//
//void do_step(long long int value, t_param *param, char sign)
//{
//	(void) param;
//	while (value > 0) {
//		write(1, &sign, 1);
//		value--;
//	}
//}
//
//void get_str_field_width(t_str_param *str_param , t_param *param)
//{
//	if (param->precision >= 0 && str_param->precision < str_param->length && param->dot == 1)
//		str_param->field_width -= str_param->precision;
//	else if (str_param->length >= str_param->field_width && (char *)param->arg_value != NULL)
//		str_param->field_width = 0;
//	else
//		str_param->field_width -= str_param->length;
//}
//
//void get_str_precision(t_param *param)
//{
//	if (param->precision == 0)
//		str_param->precision = 0;
//	else
//		str_param->precision = param->precision;
//}
//
//void print_str(t_str_param *str_param , t_param *param)
//{
//	long long int i;
//	long long int j;
//
//	i = str_param->precision;
//	j = 0;
//	do_step(str_param->field_width, param, ' ');
//	if (param->dot == 1)
//	{
//		while (j < i && str_param->str[j])
//		{
//			ft_putchar(str_param->str[j]);
//			j++;
//		}
//	} else
//		ft_putstr(str_param->str);
//}
//
//void print_str_left(t_str_param *str_param , t_param *param)
//{
//	long long int i;
//	long long int j;
//
//	i = str_param->precision;
//	j = 0;
//	if (param->dot == 1)
//	{
//		while (j < i && str_param->str[j])
//		{
//			ft_putchar(str_param->str[j]);
//			j++;
//		}
//	} else
//		ft_putstr(str_param->str);
//	do_step(str_param->field_width, param, ' ');
//}
//
//void parse_params_str(t_str_param *str_param , t_param *param)
//{
//	str_param->str = param->arg_value != NULL ? (char *)param->arg_value : "(null)";
//	str_param->length = ft_strlen(str_param->str);
//	str_param->field_width = param->width;
//	get_str_precision(str_param,param);
//	get_str_field_width(str_param, param);
//}