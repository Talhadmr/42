/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:15:45 by tdemir            #+#    #+#             */
/*   Updated: 2022/10/21 04:15:47 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spc_chrc(char c)
{
	if ((c == ' ' || c == '\t' || c == '\r'
			|| c == '\n' || c == '\v' || c == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	neg = 1;
	i = 0;
	num = 0;
	while (spc_chrc(str[i]) == 1)
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + str[i++] - 48;
		if (num * neg < -2147483648)
			return (0);
		if (num * neg > 2147483647)
			return (-1);
	}
	return (neg * num);
}
