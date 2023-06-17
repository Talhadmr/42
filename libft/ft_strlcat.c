/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:26:23 by tdemir            #+#    #+#             */
/*   Updated: 2022/10/21 03:26:53 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destSize)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!dst && !destSize)
		return (0);
	while (dst[j] && j < destSize)
		j++;
	while ((src[k]) && ((j + k + 1) < destSize))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != destSize)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
