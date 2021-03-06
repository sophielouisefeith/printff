/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:49:54 by sfeith         #+#    #+#                */
/*   Updated: 2019/11/14 15:46:25 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int i;

	i = 0;
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
