/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_analyze.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:27:43 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/10 12:55:33 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_analyze(t_co *co)
{
	co->i = 0;
	while (co->format[co->i] != '\0')
	{
		while (co->format[co->i] != '\0'
			&& co->format[co->i] != '%')
		{
			ft_putchar(co->format[co->i], co);
			co->i++;
		}
		if (co->format[co->i] == '%')
		{
			co->i++;
			ft_reset(co);
			ft_plan(co);
		}
	}
}
