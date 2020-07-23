/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:59:42 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/08 16:03:55 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>

struct	s_struct
{
	int zero;
	int min;
	int wid;
	int st_w;
	int acc;
	int st_acc;
	int dot;
}	s_fg;

size_t	ft_strlen(const char *str);
int		ft_toupper(int ch);
int		ft_printf(const char *format, ...);
int		ft_putchar(const char c, int end);
int		ft_atoi(const char *str, int *index);
void	ft_putnbr(long long int n);
void	ft_putstr(char *s, size_t len);
void	ft_print(int len, void *var, char flag);
void	ft_width_y(int len, void *var, char flag);
void	ft_nbr(const char *ptr, int index, va_list ap);
void	ft_str(const char *ptr, int index, va_list ap);
void	ft_flags(const char *ptr, int *index, va_list ap);
void	ft_acc_y(int len, int width, void *var, char flag);
void	ft_puthex(char flag_c, char flag_p, unsigned long int nb);
void	ft_h_p(const char *ptr, int index, va_list ap);

#endif
