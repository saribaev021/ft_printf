#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_tolower(int ch);
int		ft_toupper(int ch);
int		ft_putchar(char c, int end);
void	ft_putstr(char *s);
void	ft_putnbr(long long int n);
void    ft_puthex(char c, long long int nb);
void	ft_nbr(const char *ptr, int *index, va_list ap);
void   ft_str_hex(const char *ptr, int *index, va_list ap);

#endif
