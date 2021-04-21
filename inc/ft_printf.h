/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:25:30 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/20 23:12:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include "../../libft/libft.h"

# define SP_LIST "cspdiuxX%"
# define FLAG_LIST "-0.*"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define ERROR -1
# define EMPTY_FMT 0

// TO DEL
# include <stdio.h>

typedef struct s_flags
{
	bool	minus;
	bool	zero;
	bool	dot;
	bool	wc;
	int		min;	
	int		max;
	char	sp;
	int		len;
	char	*s;
}				t_flags;

int		ft_baselen(long l, int base);
char	*ft_ltoa(long n);
void	ft_print_hex(size_t nb, char *base);
void	ft_print_u(unsigned int nb);
void	ft_print_p(size_t nb);
int		ft_printf(const char *fmt, ...);
void	ft_process_c(va_list ap, t_flags arg);
void	ft_process_s(va_list ap, t_flags arg);
void	ft_process_di(va_list ap, t_flags arg);
void	ft_process_p(va_list ap, t_flags arg);
void	ft_process_per(void);
void	ft_process_u(va_list ap, t_flags arg);
void	ft_process_x(va_list ap, t_flags arg);
void	ft_process_x2(va_list ap, t_flags arg);
void	ft_putnstr(char *s, int n);
bool	ft_read_dot(t_flags *arg);
void	ft_read_fmt(va_list ap, char *s);
void	ft_read_minus(t_flags *arg);
bool	ft_read_nbr(t_flags *arg);
bool	ft_read_sp(t_flags *arg);
bool	ft_read_wc(t_flags *arg);
void	ft_read_zero(t_flags *arg);
void	ft_redirect_sp(va_list ap, t_flags arg);
t_flags	ft_set_flags(char *s);

#endif
