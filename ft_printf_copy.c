/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_copy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 16:01:37 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/09 15:46:38 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_printf_copy(char *dst, char *src, int place)
{
	int j;
	int i;

	i = 0;
	j = place;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (dst);
}
