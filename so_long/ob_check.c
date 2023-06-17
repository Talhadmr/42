/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ob_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:07:32 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 14:14:25 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collec(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg->line_count)
	{
		j = 0;
		while (j < arg->row_len)
		{
			if (arg->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_exit(t_arg *arg)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	while (i < arg->line_count)
	{
		j = 0;
		while (j < arg->row_len)
		{
			if (arg->map[i][j] == 'E')
				result++;
			j++;
		}
		i++;
	}
	if (result > 1)
	{
		return (0);
	}
	return (1);
}

int	ft_check_player(t_arg *arg)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	while (i < arg->line_count)
	{
		j = 0;
		while (j < arg->row_len)
		{
			if (arg->map[i][j] == 'P')
				result++;
			j++;
		}
		i++;
	}
	if (result > 1)
		return (0);
	return (1);
}

void	ft_last_check(t_arg *arg)
{
	if (!ft_check_collec(arg))
	{
		write (1, "missing collec\n", 16);
		exit (1);
	}
	if (!ft_check_player(arg))
	{
		write (1, "wrong player\n", 12);
		exit (1);
	}
	if (!ft_check_exit(arg))
	{
		write (1, "wrong exit\n", 12);
		exit (1);
	}
}
