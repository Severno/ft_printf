#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{

	printf("%lo", 18446744073709551615lu);
	printf("\n");
	ft_printf("%lo", 18446744073709551615lu);

	return 0;
}