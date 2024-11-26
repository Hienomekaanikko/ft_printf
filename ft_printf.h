#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int		ft_write_int(int n);
int		ft_write_unsigned_int(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_write_string(char *str);
int		ft_write_char(int c);
int		ft_hex(unsigned int n, const char format);
int		ft_write_ptr(unsigned long long n);

#endif
