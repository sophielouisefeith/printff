/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_i_d.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 10:38:07 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 15:42:57 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*ft_itoa_fill(long long int numb_len, long long int numb)
{
	char		*str;

	str = malloc(sizeof(char) * (numb_len + 1));
	if (str == 0)
		return (0);
	str[numb_len] = '\0';
	numb_len--;
	if (numb < 0)
		numb = -numb;
	while (numb_len >= 0)
	{
		str[numb_len] = (numb % 10) + 48;
		numb = numb / 10;
		numb_len--;
	}
	return (str);
}

static void			*ft_fillup(char *str, int numb, int numb_len, t_co *co)
{
	char	*str1;
	int		place;

	place = co->size_i - numb_len;
	str1 = ft_itoa_fill(numb_len, numb);
	if (co->flag_m)
		place = 0;
	if (numb >= 0)
		ft_printf_copy(str, str1, place);
	if (numb < 0)
	{
		if ((!co->precision_t && co->flag_z) || co->flag_m)
		{
			ft_printf_copy(str, str1, place);
			str[0] = '-';
		}
		else
		{
			str1[0] = '-';
			ft_printf_copy(str, str1, place);
		}
	}
	free(str1);
	return (str);
}

void				ft_circuit_i_d(t_co *co)
{
	int		numb;
	int		numb_len;
	char	*str;
	int		fill;

	numb = (int)va_arg(co->arg, int);
	numb_len = ft_count_int(numb);
	if (numb == 0 && co->p == 0)
		numb_len = 0;
	numb_len = co->p > numb_len ? co->p : numb_len;
	numb_len = numb < 0 ? (numb_len + 1) : numb_len;
	co->size_i = co->w > numb_len ? co->w : numb_len;
	co->size_i = (numb == 0 && co->p == 0 && !co->w) ? 0 :
	co->size_i;
	str = (char *)malloc(sizeof(char) * (co->size_i + 1));
	if (!str)
		return ;
	str[co->size_i] = '\0';
	fill = (co->flag_z && !co->flag_m && !co->precision_t) ? '0' : ' ';
	ft_memset(str, fill, co->size_i);
	ft_fillup(str, numb, numb_len, co);
	ft_putstr(str, co);
	free(str);
}
