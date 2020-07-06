#include "header/ft_printf.h"

long long int	ft_len_nb(long long int n)
{
	unsigned long long int nb;
	int i;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb = (unsigned long long int)-n;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
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