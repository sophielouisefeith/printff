/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_u.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:57:05 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 15:36:26 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_itoa_fill(long long int numb_len, long long int numb)
{
	char		*str;

	str = malloc(sizeof(char) * (numb_len + 1));
	if (str == 0)
		return (0);
	str[numb_len] = '\0';
	numb_len--;
	while (numb_len >= 0)
	{
		str[numb_len] = (numb % 10) + 48;
		numb = numb / 10;
		numb_len--;
	}
	return (str);
}

static void		*ft_fillup(char *str, unsigned long numb, int numb_len,
	t_co *co)
{
	char	*str1;
	int		place;

	place = co->size_i - numb_len;
	str1 = ft_itoa_fill(numb_len, numb);
	if (numb >= 0)
	{
		if (co->flag_m)
			place = 0;
		ft_printf_copy(str, str1, place);
	}
	free(str1);
	return (str);
}

void			ft_circuit_u(t_co *co)
{
	unsigned long	numb;
	int				numb_len;
	char			*str;
	int				nom;

	numb = (unsigned long long)va_arg(co->arg, unsigned int);
	numb_len = ft_count_int(numb);
	if (numb == 0 && co->p == 0)
		numb_len = 0;
	numb_len = co->p > numb_len ? co->p : numb_len;
	numb_len = numb < 0 ? (numb_len + 1) : numb_len;
	co->size_i = co->w > numb_len ? co->w : numb_len;
	co->size_i = (numb == 0 && co->p == 0 && !co->w) ? 0 : co->size_i;
	str = (char *)malloc(sizeof(char) * (co->size_i + 1));
	if (!str)
		return ;
	str[co->size_i] = '\0';
	nom = (co->flag_z && !co->flag_m && !co->precision_t) ? '0' : ' ';
	ft_memset(str, nom, co->size_i);
	ft_fillup(str, numb, numb_len, co);
	ft_putstr(str, co);
	free(str);
}
