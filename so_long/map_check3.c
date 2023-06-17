/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:53 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 13:39:35 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_safe(int y, int j, t_arg *arg)
{
	if (y >= 0 && y < arg->mat_y && j >= 0 && j < arg->mat_x)
		return (1);
	return (0);
}

int	ft_path(t_arg *arg, int i, int j)
{
	if (ft_safe(i, j, arg) && arg->matrix[i][j] != '1'\
			&& arg->visited[i][j] != '1')
	{
		arg->visited[i][j] = '1';
		if (arg->matrix[i][j] == 'F')
		{
			return (1);
		}
		if (ft_path(arg, i - 1, j))
			return (1);
		if (ft_path(arg, i, j - 1))
			return (1);
		if (ft_path(arg, i + 1, j))
			return (1);
		if (ft_path(arg, i, j + 1))
			return (1);
	}
	return (0);
}
