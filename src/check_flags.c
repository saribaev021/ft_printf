/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:04:35 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:50:28 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static	void	ft_flag_star(const char *ptr, int *i, va_list ap)
{
	if (ptr[*i] == '*')
	{
		if (s_fg.dot != 1)
		{
			s_fg.wid = va_arg(ap, int);
			s_fg.st_w = 1;
			s_fg.min = s_fg.wid < 0 && s_fg.zero == 1 &&
			s_fg.min != 1 ? 1 : s_fg.min;
		}
		if (s_fg.dot == 1)
		{
			s_fg.acc = va_arg(ap, int);
			s_fg.st_acc = 1;
		}
		(*i)++;
		if (ptr[*i] == '.')
		{
			s_fg.dot = 1;
			(*i)++;
			if (ptr[*i] == '*')
				ft_flag_star(ptr, i, ap);
		}
	}
}

void			ft_flags(const char *ptr, int *i, va_list ap)
{
	while (ptr[*i] == '-' || ptr[*i] == '0' || ptr[*i] == '.' || ptr[*i] == ' ')
	{
		if (ptr[*i] == '-')
			s_fg.min = 1;
		if (ptr[*i] == '0')
			s_fg.zero = 1;
		if (ptr[*i] == '.')
			s_fg.dot = 1;
		(*i)++;
	}
	ft_flag_star(ptr, i, ap);
	s_fg.wid = (s_fg.dot != 1 && s_fg.st_w != 1) ? ft_atoi(ptr, i) : s_fg.wid;
	ft_flag_star(ptr, i, ap);
	s_fg.acc = (s_fg.dot == 1 && s_fg.st_acc != 1) ? ft_atoi(ptr, i) : s_fg.acc;
	s_fg.acc = (s_fg.dot != 1 && s_fg.zero == 1 &&
	s_fg.min != 1) ? s_fg.wid : s_fg.acc;
	s_fg.wid = (s_fg.acc == s_fg.wid && s_fg.zero == 1) ? 0 : s_fg.wid;
}
