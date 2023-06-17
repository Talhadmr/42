/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:11:10 by tdemir            #+#    #+#             */
/*   Updated: 2022/10/21 03:14:22 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s11;
	char	*s21;
	size_t	i;

	i = 0;
	s11 = (char *)s1;
	s21 = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s11[i] != s21[i])
			return ((unsigned char)s11[i] - (unsigned char)s21[i]);
		i++;
	}
	return (0);
}
