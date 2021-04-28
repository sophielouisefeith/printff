/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 11:53:46 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/11 18:35:45 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_count_int(long long n)
{
	int count;
	int minpos;

	minpos = n;
	count = 0;
	if (minpos < 0)
	{
		while (n != 0)
		{
			n = n / 10;
			count++;
		}
	}
	if (minpos > 0)
	{
		while (n != 0)
		{
			n = n / 10;
			count++;
		}
	}
	if (minpos == 0)
		count++;
	return (count);
}
