
#include "ft_printf.h"
#include <stdio.h>


int		ft_putchar(char c, int end)
{
	static int i = 0;
	if (end == 0)
		return (i);
	write(1, &c, 1);
	i++;
	return (i);
}

static	void	ft_nb(unsigned long long int n)
{
	int		i;
	char	s[10];

	i = 0;
	while (n > 0)
	{
		s[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(s[i], 1);
	}
}

void			ft_putnbr(long long int n)
{
	unsigned long long int nb;
	int i;

	if (n > 0)
	{
		ft_nb(n);
	}
	else if (n < 0)
	{
		nb = (unsigned long long int)-n;
		ft_putchar('-', 1);
		ft_nb(nb);
	}
	else
	{
		ft_putchar(n % 10 + 48, 1);
	}

}
int main ()
{
    unsigned long int s = 1;
	printf("%lu", s); 
}