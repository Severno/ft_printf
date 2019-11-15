int		ft_unnum_of_fields(unsigned long long int num)
{
	int	count;

	count = 1;
	while ((num = num / 10))
		count++;
	return (count);
}