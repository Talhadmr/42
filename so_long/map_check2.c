/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:50 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 13:34:46 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_visited_clear(t_arg *arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arg->mat_y)
	{
		j = -1;
		while (++j < arg-> mat_x)
		{
			arg->visited[i][j] = '0';
		}
	}
}

void	ft_path_find(t_arg *arg)
{
	int	result;
	int	i;
	int	j;

	ft_visited_clear (arg);
	result = 0;
	i = -1;
	while (++i < arg->mat_y)
	{
		j = -1;
		while (++j < arg->mat_x)
		{
			if (arg->matrix[i][j] == 'P' && arg->matrix[i][j] != '1')
			{
				if (ft_path(arg, i, j))
				{
					result = 1;
					break ;
				}
			}
		}
	}
	ft_path_put(arg, result);
}

void	map_exit_chack(int i, int j, t_arg *arg)
{
	arg->matrix[i][j] = 'F';
	ft_path_find(arg);
}

void	init_matrix(t_arg *arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg->matrix[++i])
	{
		j = -1;
		while (arg->matrix[i][++j])
		{
			if (arg->matrix[i][j] == 'E')
			{
				arg->exit_i = i;
				arg->exit_j = j;
				arg->matrix[i][j] = 1;
			}
			if (arg->matrix[i][j] == 'C')
			{
				arg->matrix[i][j] = 'F';
				ft_path_find (arg);
				arg->matrix[i][j] = 'C';
			}
		}
	}
	map_exit_chack (arg->exit_i, arg->exit_j, arg);
}

void	ft_path_put(t_arg *arg, int result)
{
	arg->c_count = 0;
	if (!result)
	{
		write (1, "invalid map\n", 12);
		exit (1);
	}
}
