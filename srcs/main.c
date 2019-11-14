#include <stdio.h>
#include "../includes/ft_printf.h"

int main()
{

	printf("% .10d", -33);
	printf("\n");
	ft_printf("% .10d", -33);

	return 0;
}