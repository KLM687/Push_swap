#include "minitalk.h"

void	ft_putnbr(int n)
{
	long int	a;

	a = n;
	if (a < 0)
	{
		write(1, "-", 1);
		a = -a;
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
	{
		a = a + '0';
        write(1, &a, 1);
	}
}