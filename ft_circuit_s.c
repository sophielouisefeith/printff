/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_circuit_s.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 10:57:03 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 17:24:01 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_circuit_s(t_co *co)
{
	char	*str;
	int		width_size;

	str = va_arg(co->arg, char *);
	if (!str)
		str = "(null)";
	str = ft_substr(str, 0, co->p);
	width_size = co->w - ft_strlen(str);
	if (co->flag_m && (width_size > 0))
	{
		ft_putstr(str, co);
		ft_fill(width_size, co);
		free(str);
		return ;
	}
	if (width_size > 0)
	{
		if (co->flag_z)
			ft_fill(width_size, co);
		else
			ft_fill(width_size, co);
	}
	ft_putstr(str, co);
	free(str);
}
