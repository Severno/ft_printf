#include "../includes/ft_printf.h"

static void check_letter(int num_arr[] , int j)
{

	while (j >= 0)
	{
		if (num_arr[j] > 9)
		{
			num_arr[j] == 10 ? ft_putchar('a') : 0;
			num_arr[j] == 11 ? ft_putchar('b') : 0;
			num_arr[j] == 12 ? ft_putchar('c') : 0;
			num_arr[j] == 13 ? ft_putchar('d') : 0;
			num_arr[j] == 14 ? ft_putchar('e') : 0;
			num_arr[j] == 15 ? ft_putchar('f') : 0;
			j--;
		}
		else
			ft_putchar((char)(num_arr[j--] + '0'));
	}
}

void ft_putnbr_base(long long int n, int base)
{
	int num_arr[100];
	int i;
	int j;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (n != 0)
	{
		num_arr[i++] = n % base;
		n = n / base;
	}
	j = i - 1;
	check_letter(num_arr, j);
}

void ft_putunbr_base(unsigned long long int n, int base)
{
	int num_arr[100];
	int i;
	int j;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	while (n != 0)
	{
		num_arr[i++] = n % base;
		n = n / base;
	}
	j = i - 1;
	check_letter(num_arr, j);
}