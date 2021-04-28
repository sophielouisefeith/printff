/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_analyze_width.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:56:41 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/10 14:21:22 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		ft_analyze_width(t_co *co)
{
	if (co->format[co->i] == '*')
	{
		co->width_t = 1;
		co->w = va_arg(co->arg, int);
		if (co->w < 0)
		{
			co->w = -co->w;
			co->flag_m = 1;
		}
		co->i++;
	}
	while (ft_isdigit(co->format[co->i]) == 1)
	{
		co->w = co->w * 10 + co->format[co->i] - '0';
		co->i++;
		co->width_t = 1;
	}
}
