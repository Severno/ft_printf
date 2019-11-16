#include "../includes/ft_printf.h"

void flag_p(t_param *param)
{
	char flags[1] = "p";

	param->un_value = check_un_convention(param);
	param->val_length = ft_strlen(ft_convert_undec_base(16, check_un_convention(param), 'x'));
	calc_unreserved_fields(param);
	get_do_unprecision(param);
	get_do_unwidth(param);
	print_p(param);
	remove_current_flags(param, flags);
}