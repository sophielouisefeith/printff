/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 11:36:22 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/10 12:54:46 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, t_co *co)
{
	int i;

	i = ft_strlen(str);
	if (str != '\0')
		write(1, str, i);
	while (i)
	{
		co->len++;
		i--;
	}
}
