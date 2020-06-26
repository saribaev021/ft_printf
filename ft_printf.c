/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:38:43 by ndreadno          #+#    #+#             */
/*   Updated: 2020/06/26 21:17:06 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>


int			ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		return ((ch - 65) + 97);
	return (ch);
}

int			ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		return ((ch - 97) + 65);
	return (ch);
}

int			ft_putprc(const char *str)
{
	int i;
	int k;

	i = 0;
	while (str[i] == '%')
		i++;
	k = i / 2;
	while (k-- > 0)
		ft_putchar('%', 1);
	return (i - 1);	
}

int     		ft_printf(const char *format, ...)
{
	va_list ap; 
	int i = 0;
	const char *ptr;

	va_start(ap, format);
	ptr = format;
	while (ptr[i] != '\0')
	{
		if (ptr[i]!= '%')
			ft_putchar(ptr[i], 1);
		else if (ptr[i] == '%')
		{
			// if (ptr[i + 1] == '%')
			// 	i += ft_putprc(&ptr[i]);
			//ft_nbr(ptr, &i, ap);
			//ft_str_hex(ptr, &i, ap);
			// else if (ptr[i + 1]== 'd')
			// 	ft_putnbr(va_arg(ap, int));
			// else if (ptr[i + 1]== 'c')
			// 	ft_putchar(va_arg(ap, int), 1);
			// else if (ptr[i + 1]== 's')
			// 	ft_putstr(va_arg(ap, char*));
			// else if (ptr[i + 1] == 'x')
			// 	ft_puthex('x', va_arg(ap, unsigned int));
			// else if (ptr[i + 1] == 'X')
			// 	ft_puthex('X', va_arg(ap, unsigned int));
			if (ptr[i + 1] == 'p')
			{
				ft_putstr("0x");
				ft_puthex(va_arg(ap, size_t), 'x');
			}
		}
	}
	va_end(ap);
	return 0;
}
int main()
{
	//char q = "07FFFFFFFFFFFFFFF";
	long long int w = 9223372036854775807;
	void *ptr;
	//ptr = &w; 
	char *name = "Канат";
	char c  = '\n';
	int d = 18;
	char *s = "лет";
	unsigned int i = 123124234;
	//unsigned int w = 123124234;
	//ft_printf("%cпривет %%%% меня зовут %s, мне %d %s%c%x%c%X", c, name, d, s, c, i, c, i);
	//printf("%cпривет меня зовут %s, мне %ds %s%c%x%c%X", c, name, d, s, c, i, c, i);
	ft_printf("%p\n", w);
	//ft_puthex('x', w);
	return (0);
}