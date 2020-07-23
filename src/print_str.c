/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:10:30 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:32:36 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		ft_acc_str(int len, char *var, char flag)
{
	s_fg.wid = s_fg.acc < len ?
	s_fg.wid - s_fg.acc : s_fg.wid - len;
	if (s_fg.min == 0)
	{
		while (s_fg.wid-- > 0)
			ft_putchar(' ', 1);
		ft_print(s_fg.acc, var, flag);
	}
	else if (s_fg.min == 1)
	{
		ft_print(s_fg.acc, var, flag);
		while (s_fg.wid-- > 0)
			ft_putchar(' ', 1);
	}
	else
		ft_print(s_fg.acc, var, flag);
}

static void		ft_width_str(int len, void *var, char flag)
{
	if (s_fg.wid < 0)
	{
		s_fg.wid *= -1;
		s_fg.min = 1;
	}
	s_fg.wid = s_fg.dot != 1 ||
	s_fg.acc < 0 ? s_fg.wid - len : s_fg.wid;
	if (s_fg.dot == 1 && s_fg.acc >= 0)
		ft_acc_str(len, var, flag);
	else if (s_fg.min != 1)
	{
		while (s_fg.wid-- > 0)
			ft_putchar(' ', 1);
		ft_print(len, var, flag);
	}
	else if (s_fg.min == 1)
	{
		ft_print(len, var, flag);
		while (s_fg.wid-- > 0)
			ft_putchar(' ', 1);
	}
}

static void		ft_char_prc(char c)
{
	if (s_fg.wid != 0)
		ft_width_y(1, &c, 'c');
	else if (s_fg.acc != 0)
		ft_acc_y(1, 0, &c, 'c');
	else
		ft_putchar(c, 1);
}

static void		ft_s(char *str, int len)
{
	if (s_fg.wid != 0)
		ft_width_str(len, str, 's');
	else if (s_fg.acc > 0)
		ft_acc_str(len, str, 's');
	else if (s_fg.acc == 0 && s_fg.dot == 1)
		return ;
	else
		ft_putstr(str, len);
}

void			ft_str(const char *ptr, int index, va_list ap)
{
	char	*str;
	char	c;
	size_t	len;

	c = '%';
	str = "";
	if (ptr[index] == 'c')
		c = va_arg(ap, int);
	if (ptr[index] == 's')
		str = va_arg(ap, char*);
	if (ptr[index] == 's' && str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr[index] == 's')
		ft_s(str, len);
	else if (ptr[index] == 'c' || ptr[index] == '%')
		ft_char_prc(c);
}
