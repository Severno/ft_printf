#include "../includes/ft_printf.h"

void remove_conflicted_flags(t_param *param,long double value)
{
	char *tmp;
	if ((ft_strstr(param->flags, "0")) && (ft_strstr(param->flags, "-")))
	{
		tmp = param->flags;
		param->flags = ft_find_and_remove_char(param->flags, '0');
		free(tmp);
	}
	if ((ft_strstr(param->flags, " ")) && ((ft_strstr(param->flags, "+")
			|| check_convention(param) < 0
			|| value < 0)))
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
		ft_find_and_remove_char(param->flags, flags[i++]);
}
