/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_c.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:56:52 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/09 18:06:57 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_circuit_c(t_co *co)
{
	unsigned char	c;

	c = (unsigned char)va_arg(co->arg, int);
	if ((co->flag_m) || (!co->flag_z && !co->flag_m))
	{
		if (co->flag_m)
			ft_putchar(c, co);
		while (co->w - 1 > 0)
		{
			ft_putchar(' ', co);
			co->w--;
		}
		if (!co->flag_z && !co->flag_m)
			ft_putchar(c, co);
	}
	if (co->flag_z && !co->flag_m)
	{
		while (co->w - 1 > 0)
		{
			ft_putchar('0', co);
			co->w--;
		}
		ft_putchar(c, co);
	}
}
