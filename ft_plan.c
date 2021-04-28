/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_plan.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:43:31 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 17:54:57 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_plan(t_co *co)
{
	if (co->format[co->i] != '\0')
		ft_analyze_flags(co);
	if (co->format[co->i] != '\0')
		ft_analyze_width(co);
	if (co->format[co->i] != '\0')
		ft_analyze_precision(co);
	if (co->format[co->i] != '\0')
		ft_analyze_conversions(co);
}
