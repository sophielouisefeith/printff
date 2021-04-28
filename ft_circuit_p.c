/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_p.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:57:00 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/13 11:11:02 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		*ft_printf_copy_p(char *dst, char *src, int place)
{
	int j;
	int i;

	i = 0;
	j = place;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[1] = 'x';
	return (dst);
}

static void		*ft_fillup(char *str, char *strhex, t_co *co)
{
	char	*str1;
	int		place;

	str1 = (char *)malloc(sizeof(char) * (co->numb_len + 1));
	str1[co->numb_len] = '\0';
	ft_memset(str1, '0', co->numb_len);
	place = co->numb_len - co->size_x;
	ft_printf_copy_p(str1, strhex, place);
	place = co->size_i - co->numb_len;
	if (co->flag_m)
		co->place = 0;
	if (!co->flag_m)
		co->place = co->size_i - co->numb_len;
	ft_printf_copy(str, str1, co->place);
	free(strhex);
	free(str1);
	return (str);
}

void			ft_circuit_p(t_co *co)
{
	char	*str;
	char	*strhex;

	co->base = 16;
	co->numb = (unsigned long long)va_arg(co->arg, void *);
	if (co->numb == 0 && co->p == 0)
		strhex = ft_strdup("");
	else
		strhex = ft_itoa_base(co->numb, co->base, co);
	co->numb_len = co->size_x;
	co->numb_len = co->p > co->numb_len ? co->p + 2 : co->numb_len + 2;
	co->numb_len = co->numb < 0 ? (co->numb_len + 1) : co->numb_len;
	co->size_i = co->w > co->numb_len ? co->w : co->numb_len;
	co->size_i = (co->numb == 0 && !co->p && !co->precision_t && !co->w) ? 0 :
	co->size_i;
	str = (char *)malloc(sizeof(char) * (co->size_i + 1));
	if (!str)
		return ;
	str[co->size_i] = '\0';
	co->fill = (co->flag_z && !co->flag_m && !co->precision_t) ? '0' : ' ';
	ft_memset(str, ' ', co->size_i);
	ft_fillup(str, strhex, co);
	ft_putstr(str, co);
	free(str);
}
