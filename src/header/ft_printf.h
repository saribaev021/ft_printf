#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>

struct s_struct
{
	int zero;
	int minus;
	int width;
	int star_width;
	int acc;
	int star_acc;
	int dot;
}	s_flags;

size_t	ft_strlen(const char *str);
int		ft_toupper(int ch);
int		ft_printf(const char *format, ...);
int		ft_putchar(const char c, int end);
int		ft_atoi(const char *str, int * index);
void	ft_putnbr(long long int n);
void	ft_putstr(char *s, size_t len);
void	ft_print(int len, void *var, char flag);
void	ft_acc_y(int len, void *var, char flag);
void	ft_width_y(int len, void *var, char flag);
void	ft_nbr(const char *ptr, int index, va_list ap);
void	ft_str(const char *ptr, int index, va_list ap);
void	ft_flags(const char *ptr, int *index, va_list ap);
void    ft_puthex(char flag_c, char flag_p, unsigned long int nb);
void	ft_print_hex_pointer(const char *ptr, int index, va_list ap);

#endif
