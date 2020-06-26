#include "ft_printf.h"

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

// void			ft_nbr(const char *ptr, int *index, va_list ap)
// {
// 	// unsigned int	u;
// 	// int 			i;
// 	// char		 	str[10];
// 	// if (ptr[*index] == 'd' || ptr[*index] == 'i')
// 	// {
// 	// 	ft_putnbr(va_arg(ap, int));
// 	// 	*index++;
// 	// }
// 	// else if(ptr[*index] == 'u')
// 	// {
// 	// 	ft_putnbr(va_arg(ap, unsigned int));
// 	// 	*index++;
// 	// }
// }