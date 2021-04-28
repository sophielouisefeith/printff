/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 10:31:24 by sfeith         #+#    #+#                */
/*   Updated: 2020/01/09 20:22:30 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ft_count(unsigned long long n, t_co *co)
{
	co->size_x = 0;
	if (n < 0)
	{
		co->size_x++;
	}
	if (n == 0)
		co->size_x = 1;
	while (n > 0)
	{
		n = n / 16;
		co->size_x++;
	}
	return (co->size_x);
}

char			*ft_itoa_base(unsigned long long n, int base, t_co *co)
{
	int						j;
	char					*res;
	int						temp;

	j = ft_count(n, co);
	res = malloc(sizeof(char) * (j + 1));
	if (res == NULL)
		return (NULL);
	res[j] = '\0';
	while (j > 0)
	{
		j--;
		temp = n % base;
		if (temp >= 0 && temp <= 9)
			res[j] = temp + 48;
		if (temp > 9 && temp < 16)
		{
			if (co->format[co->i] == 'x' || co->format[co->i] == 'p')
				res[j] = temp + 87;
			if (co->format[co->i] == 'X')
				res[j] = temp + 55;
		}
		n = n / base;
	}
	return (res);
}
