/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 11:18:45 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/10 15:19:41 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset(t_co *co)
{
	co->width_t = 0;
	co->flag_z = 0;
	co->flag_m = 0;
	co->width_s = 0;
	co->width_res = 0;
	co->w = 0;
	co->precision_t = 0;
	co->size_i = 0;
	co->p = -1;
	co->numb = 0;
	co->size_x = 0;
	co->place = 0;
}
