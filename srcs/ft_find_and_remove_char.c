#include "../includes/ft_printf.h"

char *ft_find_and_remove_char(char *str, char find)
{
	size_t i;
	size_t j;
	char *new_str;

	i = 0;
	j = 0;
	if (str == NULL)
		return NULL;
	while (str[i])
	{
		if (str[i] == find)
		{
			j = i;
			while (str[j + 1])
			{
				str[j] = str[j + 1];
				j++;
			}
			str[j] = '\0';
			break;
		}
		i++;
	}
	new_str = ft_strdup(str);
	return new_str;
}
