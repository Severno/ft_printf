#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	ft_printf("%5.10d\n", 21);
	printf("%5.10d\n", 21);
	ft_printf("%10s\n", "WHO AM I");
	printf("%10s\n", "WHO AM I");
	return 0;
}