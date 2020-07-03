/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:57:34 by ndreadno          #+#    #+#             */
/*   Updated: 2020/06/30 12:34:32 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_checksp(const char *str, int index)
{
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\v' ||
	str[index] == '\f' || str[index] == '\r' || str[index] == '\n')
		index++;
	return (index);
}

static	int		ft_conv(const char *str, int *index, int l)
{
	int res;
	int k;

	res = 0;
	k = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		if (str[*index] != '0')
			k++;
		if (k > 19)
		{
			if (l > 0)
				return (0);
			else
			{
				return (-1);
			}
		}
		res = res * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (res);
}

int				ft_atoi(const char *str, int *index)
{
	int	res;
	int	minus;

	minus = 0;
	*index = ft_checksp(str, *index);
	if (str[*index] == '-')
	{
		minus++;
		(*index)++;
	}
	if (str[*index] == '+' && str[*index - 1] != '-')
		(*index)++;
	res = ft_conv(str, index, minus);
	if (minus > 0)
		res = res * -1;
	if (str[*index] == '.')
	{
		s_flags.dot = 1;
		(*index)++;
	}	
	return (res);
}
