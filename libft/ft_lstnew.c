/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:02:35 by tdemir            #+#    #+#             */
/*   Updated: 2022/10/21 03:07:37 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = (t_list *)malloc(sizeof(t_list));
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}
