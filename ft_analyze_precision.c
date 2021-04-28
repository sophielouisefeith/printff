/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_analyze_precision.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:56:39 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/10 15:07:54 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_analyze_precision(t_co *co)
{
	co->p = -1;
	if (co->format[co->i] == '.')
	{
		co->precision_t = 1;
		co->p = 0;
		co->i++;
		if (co->format[co->i] == '*')
		{
			co->p = va_arg(co->arg, int);
			co->i++;
		}
		while (ft_isdigit(co->format[co->i]) == 1)
		{
			co->p = co->p * 10 + co->format[co->i] - '0';
			co->i++;
		}
	}
}
