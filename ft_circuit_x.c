/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_x.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:57:07 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 17:12:48 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		*ft_fillup(char *str, char *strhex, t_co *co)
{
	char *str1;

	str1 = (char *)malloc(sizeof(char) * (co->numb_len + 1));
	str1[co->numb_len] = '\0';
	ft_memset(str1, '0', co->numb_len);
	co->place = co->numb_len - co->size_x;
	ft_printf_copy(str1, strhex, co->place);
	if (co->flag_m)
		co->place = 0;
	if (!co->flag_m)
		co->place = co->size_i - co->numb_len;
	ft_printf_copy(str, str1, co->place);
	free(strhex);
	free(str1);
	return (str);
}

void			ft_circuit_x(t_co *co)
{
	char *str;
	char *strhex;

	co->base = 16;
	co->numb = (unsigned)va_arg(co->arg, unsigned int);
	if (co->numb == 0 && co->p == 0)
		strhex = ft_strdup("");
	else
		strhex = ft_itoa_base(co->numb, co->base, co);
	co->numb_len = co->size_x;
	co->numb_len = co->p > co->numb_len ? co->p : co->numb_len;
	co->numb_len = co->numb < 0 ? (co->numb_len + 1) : co->numb_len;
	co->size_i = co->w > co->numb_len ? co->w : co->numb_len;
	co->size_i = (co->numb == 0 && co->p == 0 && !co->w) ? 0 : co->size_i;
	str = (char *)malloc(sizeof(char) * (co->size_i + 1));
	if (!str)
		return ;
	str[co->size_i] = '\0';
	co->fill = (co->flag_z && !co->flag_m && !co->precision_t) ? '0' : ' ';
	ft_memset(str, co->fill, co->size_i);
	ft_fillup(str, strhex, co);
	ft_putstr(str, co);
	free(str);
}
