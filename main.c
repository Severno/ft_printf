#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{

	int a;
	a = 10;
	printf("%100p", &a);
	printf("\n");
	ft_printf("%100p", &a);
	return 0;
}