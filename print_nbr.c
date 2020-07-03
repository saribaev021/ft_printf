#include "ft_printf.h"
#include <stdio.h>

long long int	ft_len_nb(long long int n)
{
	unsigned long long int nb;
	int i;

	i = 0;
	nb = n;
	if (n < 0)
		nb = (unsigned long long int)-n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static	void	ft_nb(unsigned long long int n)
{
	int		i;
	char	s[20];

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



void			ft_nbr(const char *ptr, int index, va_list ap)
{
	int	d;
	int len;

	d = 0;
	if (ptr[index] == 'd' || ptr[index] == 'i')
	{
		d = va_arg(ap, int);
	}
	if(ptr[index] == 'u')
	{
		d = va_arg(ap, int);
	}
	len = ft_len_nb(d);
	if (ptr[index] == 'u' || ptr[index] == 'd' || ptr[index] == 'i')
	{
		if (s_flags.width != 0)
			ft_width_y(len, &d, ptr[index]);
		else if (s_flags.acc != 0 && s_flags.acc > len)
			ft_acc_y(len, &d, ptr[index]);
		else
			ft_putnbr(d);
	}
}