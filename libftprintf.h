/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 16:26:54 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 18:43:58 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_co
{
	const char			*format;
	size_t				i;
	int					len;
	va_list				arg;
	int					flag_m;
	int					flag_z;
	int					width_s;
	int					width_t;
	int					width;
	int					width_res;
	int					w;
	int					precision_t;
	int					p;
	long				count_i;
	unsigned long long	numb;
	int					base;
	int					count_p;
	int					size_i;
	int					size_x;
	unsigned int		fill;
	int					numb_len;
	int					place;

}					t_co;

int					ft_printf(const char *format, ...);
void				ft_reset(t_co *co);
void				ft_analyze(t_co *co);
void				ft_plan(t_co *co);
void				ft_analyze_flags(t_co *co);
void				ft_analyze_precision(t_co *co);
void				ft_analyze_conversions(t_co *co);
void				ft_analyze_width(t_co *co);
void				ft_putchar(char c, t_co *co);
void				ft_circuit_c(t_co *co);
void				ft_circuit_s(t_co *co);
void				ft_putstr(char *str, t_co *co);
void				ft_fill(int size, t_co *co);
void				ft_circuit_p(t_co *co);
void				ft_circuit_i_d(t_co *co);
void				ft_circuit_u(t_co *co);
void				ft_circuit_x(t_co *co);
int					ft_count_int(long long n);
char				*ft_itoa_base(unsigned long long n, int base, t_co *co);
void				ft_circuit_procent(t_co *co);
void				*ft_printf_copy(char *dst, char *src, int padding);

#endif
