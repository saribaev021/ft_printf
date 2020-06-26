#include "ft_printf.h"

int		ft_putchar(char c, int end)
{
	static int i = 0;
	if (end == 0)
		return (i);
	write(1, &c, 1);
	i++;
	return (i);
}

void		ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], 1);
		i++;
	}
}

void    ft_puthex(char c, long long int nb)
{
	char *str;
	int remainder[20];
	int i;

	i = 0;
	str = "0123456789abcdef";
	while (nb > 16)
	{
		remainder[i] = nb % 16;	
		nb = nb / 16;
		i++;
	}
	if (c != 'x')
	{
		ft_putchar(ft_toupper(str[nb]), 1);
		while (i-- > 0)
			ft_putchar(ft_toupper(str[remainder[i]]), 1);
	}
	else
	{
		ft_putchar(str[nb], 1);
		while (i-- > 0)
			ft_putchar(str[remainder[i]], 1);
	}		
}
// void   ft_str_hex(const char *ptr, int *index, va_list ap)
// {
//     if (ptr[*index] == 'c')
//     {
//         ft_putchar(va_arg(ap, int), 1);
//         *index++;
//     }
//     else if (ptr[*index] == 's')
//     {
//         ft_putstr(va_arg(ap, char*));
//         *index++;
//     }
//     else if (ptr[*index] == 'x')
//     {
//         ft_puthex(va_arg(ap, unsigned int), 'x');
//         *index++;
//     }
//     else if (ptr[*index] == 'X')
//     {
//         ft_puthex(va_arg(ap, unsigned int), 'X');
//         *index++;
//     }
//     else if (ptr[*index] == 'p')
//     {
// 		ft_putstr("ox");
//         ft_puthex(va_arg(ap, unsigned long), 'x');
//         *index++;
//     }
// }

