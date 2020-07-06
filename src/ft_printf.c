/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:38:43 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/06 14:02:18 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include <stdio.h>
#include <string.h>

static	int			ft_putprc(const char *str, int j)
{
	int i;
	int k;

	i = 0;
	while (str[i] == '%')
		i++;
	if (j)
		return (i % 2);
	k = i / 2;
	while (k-- > 0)
		ft_putchar('%', 1);
	return (i - 1);	
}




int     		ft_printf(const char *format, ...)
{
	va_list ap; 
	int i = 0;
	int flag;
	const char *ptr;

	va_start(ap, format);
	ptr = format;
	while (ptr[i] != '\0')
	{
		flag = 1;
		if (ptr[i]!= '%')
			ft_putchar(ptr[i], 1);
		else if (ptr[i++] == '%')
		{
			if (ptr[i] == '%')
			{
				flag = ft_putprc(&ptr[i - 1], 1);
				i += ft_putprc(&ptr[i - 1], 0);
			}
			if (((ptr[i] >= '0' && ptr[i] <= '9') || ptr[i] == '-' || ptr[i] == '.' || ptr[i] == '*') && flag)
				ft_flags(ptr, &i, ap);
			if (flag)
			{
				ft_nbr(ptr, i, ap);
				ft_print_hex_pointer(ptr, i, ap);
				ft_str(ptr, i, ap);
			}
		}
		if (!flag)
			i--;
		i++;
	}
	va_end(ap);
	return (ft_putchar('0', 0));
}
