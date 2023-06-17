/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:53:52 by maygen            #+#    #+#             */
/*   Updated: 2022/10/21 12:03:06 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*my_str;
	size_t	counter;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	my_str = (char *)malloc(sizeof(char) * len + 1);
	if (!my_str)
		return (NULL);
	counter = 0;
	while (len--)
		my_str[counter++] = s[start++];
	my_str[counter] = '\0';
	return (my_str);
}
