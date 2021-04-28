/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sfeith <sfeith@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 14:41:08 by sfeith         #+#    #+#                */
/*   Updated: 2019/11/18 12:06:01 by sfeith        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *t;

	t = malloc(sizeof(t_list));
	if (t)
	{
		t->content = content;
		t->next = NULL;
	}
	return (t);
}
