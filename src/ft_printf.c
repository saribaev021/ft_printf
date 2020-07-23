/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:38:43 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:50:21 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		ft_putprc(const char *str, int j)
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

static void		ft_parsing(const char *ptr, int *i, int *flag, va_list ap)
{
	s_fg.dot = 0;
	s_fg.min = 0;
	s_fg.zero = 0;
	s_fg.wid = 0;
	s_fg.acc = 0;
	s_fg.st_acc = 0;
	s_fg.st_w = 0;
	if (ptr[*i] == '%')
	{
		*flag = ft_putprc(&ptr[*i - 1], 1);
		*i += ft_putprc(&ptr[*i - 1], 0);
	}
	if (((ptr[*i] >= '0' && ptr[*i] <= '9') || ptr[*i] == '-' ||
	ptr[*i] == '.' || ptr[*i] == '*' || ptr[*i] == ' ') && *flag)
		ft_flags(ptr, i, ap);
	if (*flag)
	{
		ft_nbr(ptr, *i, ap);
		ft_h_p(ptr, *i, ap);
		ft_str(ptr, *i, ap);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			flag;
	const char	*ptr;

	i = 0;
	va_start(ap, format);
	ptr = format;
	while (ptr[i] != '\0')
	{
		flag = 1;
		if (ptr[i] != '%')
			ft_putchar(ptr[i], 1);
		else if (ptr[i++] == '%')
			ft_parsing(ptr, &i, &flag, ap);
		if (!flag)
			i--;
		i += ptr[i] != '\0' ? 1 : 0;
	}
	va_end(ap);
	return (ft_putchar('0', 0));
}
