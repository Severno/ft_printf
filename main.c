#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{

	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("Width trick: %d \n", 5, 10);
	printf ("%s \n", "A string");

	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("Width trick: %d \n", 5, 10);
	ft_printf ("%s \n", "A string");

	return 0;
}