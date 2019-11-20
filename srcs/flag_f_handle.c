int			is_nan(long double floatNum)
{
	return floatNum != floatNum;
}

int			is_inf(long double floatNum)
{
	if (floatNum == -(1.0 / 0.0))
		return 2;
	else if (floatNum == (1.0 / 0.0))
		return 1;
	else
		return 0;
}

int			is_value(long double floatNum)
{
	if (is_inf(floatNum) || is_nan(floatNum))
		return (0);
	else
		return (1);
}
