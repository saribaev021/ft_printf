/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:38:43 by ndreadno          #+#    #+#             */
/*   Updated: 2020/06/22 10:43:57 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_puthex(char c, unsigned int nb)
{
	char *str;
	int remainder[16];
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
		ft_putchar(ft_toupper(str[nb]));
		while (i-- > 0)
			ft_putchar(ft_toupper(str[remainder[i]]));
	}
	else
	{
		ft_putchar(str[nb]);
		while (i-- > 0)
			ft_putchar(str[remainder[i]]);
	}		
}
// int     ft_printf(const char *format, ...)
// {
// 	va_list ap; 
// 	int d;
// 	char c;
// 	char *s;
// 	const char *ptr;

// 	va_start(ap, format);
// 	ptr = format;
// 	while (*ptr != '\0')
// 	{
// 		if(*ptr != '%')
// 		{
// 			ft_putchar(*ptr);
// 			*ptr++;
// 			continue;
// 		}
// 		if (*++ptr == 'd')
// 		{
// 			d = va_arg(ap, int);
// 			ft_putnbr(d);
// 			*ptr++;
// 			continue;
// 		}
// 		if (*ptr == 'c')
// 		{
// 			c = va_arg(ap, int);
// 			ft_putchar(c);
// 			*ptr++;
// 			continue;
// 		}
// 		if (*ptr == 's')
// 		{
// 			s = va_arg(ap, char*);
// 			ft_putstr(s);
// 			*ptr++;
// 			continue;
// 		}
// 	}
// 	va_end(ap);
// }
int main()
{
	char *name = "Канат";
	char c  = '\n';
	int d = 18;
	char *s = "лет";
	unsigned int i = 123124234;
	unsigned int w = 123124234;
	//ft_printf("привет меня зовут %s, мне %d %s%c", name, d, s, c);
	printf("%X\n", i);
	ft_puthex('x', w);
	return (0);
}