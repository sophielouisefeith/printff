/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_analyze_conversions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:56:36 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 18:28:35 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_analyze_conversions(t_co *co)
{
	char *check;

	check = "cdipsuxX%";
	if (ft_strchr(check, co->format[co->i]))
	{
		if (co->format[co->i] == 'c')
			ft_circuit_c(co);
		else if (co->format[co->i] == 's')
			ft_circuit_s(co);
		else if (co->format[co->i] == 'x' ||
			co->format[co->i] == 'X')
			ft_circuit_x(co);
		else if (co->format[co->i] == 'i' ||
			co->format[co->i] == 'd')
			ft_circuit_i_d(co);
		else if (co->format[co->i] == 'u')
			ft_circuit_u(co);
		else if (co->format[co->i] == '%')
			ft_circuit_procent(co);
		else if (co->format[co->i] == 'p')
			ft_circuit_p(co);
	}
	co->i++;
}
