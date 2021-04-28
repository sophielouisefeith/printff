/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_analyze_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:56:33 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 18:19:57 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_analyze_flags(t_co *co)
{
	while (ft_strchr(" lh+#", co->format[co->i]))
		co->i++;
	while (co->format[co->i] == '0'
		|| co->format[co->i] == '-')
	{
		if (co->format[co->i] == '0')
			co->flag_z = 1;
		if (co->format[co->i] == '-')
			co->flag_m = 1;
		co->i++;
	}
}
