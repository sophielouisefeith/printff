/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_procent.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:35:09 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 17:29:24 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_circuit_procent(t_co *co)
{
	if ((co->flag_m) || (!co->flag_z && !co->flag_m))
	{
		if (co->flag_m)
			ft_putchar('%', co);
		while (co->w - 1 > 0)
		{
			ft_putchar(' ', co);
			co->w--;
		}
		if (!co->flag_z && !co->flag_m)
			ft_putchar('%', co);
	}
	if (co->flag_z && !co->flag_m)
	{
		while (co->w - 1 > 0)
		{
			ft_putchar('0', co);
			co->w--;
		}
		ft_putchar('%', co);
	}
}
