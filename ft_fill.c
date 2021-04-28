/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:08:57 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/09 16:55:23 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fill(int size, t_co *co)
{
	if (co->flag_z)
	{
		while (size > 0)
		{
			ft_putchar('0', co);
			size--;
		}
	}
	while (size > 0)
	{
		ft_putchar(' ', co);
		size--;
	}
}
