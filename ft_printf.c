/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 12:10:01 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/09 18:20:30 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_co *co;

	co = (t_co*)malloc(sizeof(t_co));
	co->len = 0;
	if (!co)
		return (-1);
	co->format = format;
	if (format)
	{
		va_start(co->arg, format);
		ft_analyze(co);
		va_end(co->arg);
	}
	free(co);
	return (co->len);
}
