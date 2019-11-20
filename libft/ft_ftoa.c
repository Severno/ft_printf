#include "libft.h"

static long double round(int precision)
{
	long double rounder;

	rounder = 0.5;
	while (precision)
	{
		rounder /= 10;
		precision--;
	}
	return rounder;
}

static char * inf_nan_handle(long double floatNum)
{
	if (floatNum == -(1.0 / 0.0))
		return ("-inf");
	else if (floatNum == (1.0 / 0.0))
		return ("inf");
	else if (floatNum != floatNum)
		return "nan";
	return "";
}

static void ftoa_init(int *precision, long double *floatNum, long long *intPart)
{
	*floatNum < 0 ? *floatNum = -*floatNum : 0;
	*precision > MAX_PRECISION ? *precision = MAX_PRECISION : 0;
	*precision == -1 ? *precision = 6 : 0;
	*precision >= 0 ? *floatNum += round(*precision) : 0;
	*intPart = (long long)*floatNum;
	*floatNum -= (long double)*intPart;
	*precision > 19 && *precision < 53 ? *floatNum += round(*precision) : 0;
}

static void add_exponent(char *res, size_t *i, long long *intPart)
{
	size_t j;
	size_t tmp_i;

	char tmp;

	j = 0;
	tmp_i = *i;
	res[tmp_i - 1] == '-' ? j++ : 0;
	if (*intPart == 0)
		res[(*i)++] = '0';
	else
	{
		while (*intPart)
		{
			res[tmp_i++] = '0' + *intPart % 10;
			*intPart /= 10;
		}
		*i = tmp_i--;
		while (tmp_i > j)
		{
			tmp = res[tmp_i];
			res[(tmp_i)] = res[j];
			res[j++] = tmp;
			tmp_i--;
		}
	}
}

static void add_mantiss(long double *floatNum, int *precision, char *res, size_t *i)
{
	char tmp;

	if (*precision)
	{
		res[(*i)++] = '.';
		while (*precision)
		{
			*floatNum *= 10.0;
			tmp = (char)*floatNum;
			res[(*i)++] = '0' + tmp;
			*floatNum -= tmp;
			*precision -= 1;
		}
	}
	res[*i] = '\0';
}



char * ft_ftoa(long double floatNum, char * buf, int precision, int sign)
{
	long long intPart;
	size_t i;

	i = 0;
	if (!ft_strequ(inf_nan_handle(floatNum), ""))
		return inf_nan_handle(floatNum);
	if (floatNum < 0)
	{
		floatNum = -floatNum;
		if (sign == 1)
			buf[i++] = '-';
	}
	ftoa_init(&precision, &floatNum, &intPart);
	add_exponent(buf, &i, &intPart);
	add_mantiss(&floatNum, &precision, buf, &i);
	return buf;
}