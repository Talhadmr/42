/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:16:31 by tdemir            #+#    #+#             */
/*   Updated: 2022/10/21 04:13:16 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t	i;
	char	*src1;

	i = 0;
	src1 = (char *)src;
	if (!src && !len)
		return (NULL);
	while (i < len)
	{
		src1[i] = c;
		i++;
	}
	return (src);
}
