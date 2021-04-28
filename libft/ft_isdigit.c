/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:33:32 by sfeith         #+#    #+#                */
/*   Updated: 2019/11/14 15:46:05 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int i;

	i = 0;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}