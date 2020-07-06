
#include "header/ft_printf.h"

unsigned long int ft_len_xex(unsigned long int nb)
{
	int i;

	i = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 1);
}

void	ft_print_hex_pointer(const char *ptr, int index, va_list ap)
{
	unsigned long int x;
	int len;

	x = 0;
	if (ptr[index] == 'x' || ptr[index] == 'X')
        x = va_arg(ap, unsigned int);
    if (ptr[index] == 'p')
        x = va_arg(ap, unsigned long int);
	len = ft_len_xex(x);
	if (ptr[index] == 'x')
	{
		if (s_flags.width != 0)
			ft_width_y(len, &x, ptr[index]);
		else if (s_flags.acc != 0 && s_flags.acc > len)
			ft_acc_y(len, &x, ptr[index]);
		else
			ft_puthex(ptr[index], 'x', x);
	}
	if (ptr[index] == 'p')
	{
		if (s_flags.width != 0)
			ft_width_y(len + 2, &x, 'p');
		else if (s_flags.acc != 0 && s_flags.acc > len)
			ft_acc_y(len + 2, &x, 'p');
		else
			ft_puthex('x', 'p', x);
	}
}