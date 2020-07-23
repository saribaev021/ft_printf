/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:15:02 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:32:27 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		ft_short_cod(int len, void *var, char sp)
{
	len += s_fg.zero == 1 && s_fg.dot != 1 && (sp == 'd' ||
	sp == 'i') && *((int*)var) < 0 ? 1 : 0;
	while ((s_fg.acc - len) > 0)
	{
		if (*((int*)var) < 0 && len < s_fg.acc &&
		(sp == 'd' || sp == 'i'))
		{
			*((int*)var) *= -1;
			ft_putchar('-', 1);
		}
		ft_putchar('0', 1);
		s_fg.acc--;
	}
}

static void		ft_width_minus_y(int len, int width, void *var, char flag)
{
	width += s_fg.dot == 1 && s_fg.acc == 0 ? 1 : 0;
	if (s_fg.dot == 1 && s_fg.acc == 0)
	{
		while (width-- > 0)
			ft_putchar(' ', 1);
		return ;
	}
	ft_print(0, var, flag);
	while (width-- > 0)
		ft_putchar(' ', 1);
}

void			ft_acc_y(int len, int width, void *var, char flag)
{
	if (s_fg.acc > len && s_fg.acc < s_fg.wid && s_fg.min == 0)
	{
		while (width-- > 0)
			ft_putchar(' ', 1);
		ft_short_cod(len, var, flag);
		ft_print(0, var, flag);
	}
	else if (s_fg.acc > len && len < s_fg.wid)
	{
		ft_short_cod(len, var, flag);
		ft_print(0, var, flag);
		while (width-- > 0)
			ft_putchar(' ', 1);
	}
	else if (s_fg.acc > len && s_fg.acc > s_fg.wid)
	{
		ft_short_cod(len, var, flag);
		ft_print(0, var, flag);
	}
}

void			ft_width_y(int len, void *var, char flag)
{
	int width;

	if (s_fg.wid < 0)
	{
		s_fg.wid *= -1;
		s_fg.min = 1;
	}
	width = s_fg.dot == 1 && s_fg.acc > len ?
	s_fg.wid - s_fg.acc : s_fg.wid - len;
	width = (flag == 'd' || flag == 'i') &&
	*((int*)var) < 0 ? width - 1 : width;
	if (s_fg.dot == 1 && s_fg.acc > len)
		ft_acc_y(len, width, var, flag);
	else if (s_fg.min != 1)
	{
		width += s_fg.dot == 1 && s_fg.acc == 0 ? 1 : 0;
		while (width-- > 0)
			ft_putchar(' ', 1);
		if (s_fg.dot == 1 && s_fg.acc == 0 && flag != 'p')
			return ;
		ft_print(0, var, flag);
	}
	else if (s_fg.min == 1)
		ft_width_minus_y(len, width, var, flag);
}
