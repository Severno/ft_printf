#include "../includes/ft_printf.h"

static void calc_percent_width(t_param *param)
{
	param->do_width = param->width - 1;
}

void flag_percent(t_param *param)
{
	char flags[1] = "%";

	calc_percent_width(param);
	print_percent(param);
	remove_current_flags(param, flags);
}