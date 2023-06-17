/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:45 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/11 18:17:56 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_add(t_arg *arg, int x, int y)
{
	arg->player_x = x;
	arg->player_y = y;
}

void	ft_numb_of_elem_check(t_arg *arg)
{
	int	x;
	int	y;

	arg->p_count = 0;
	arg->e_count = 0;
	arg->c_count = 0;
	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x])
		{
			if (arg->map[y][x] == 'P')
			{
				ft_add(arg, x, y);
				arg->p_count++;
			}
			if (arg->map[y][x] == 'E')
				arg->e_count++;
			if (arg->map[y][x] == 'C')
				arg->c_count++;
			x++;
		}
		y++;
	}
}

void	ft_map_mani(t_arg *arg, int x, int y)
{
	if (arg->map[y][x] != '1' && arg->map[y][x] != 'E')
	{
		arg->map[arg->player_y][arg->player_x] = '0';
		if (arg->map[y][x] == 'C')
			arg->c_count--;
		arg->move++;
		ft_putnbr(arg->move);
		write(1, "\n", 1);
		arg->map[y][x] = 'P';
		arg->player_x = x;
		arg->player_y = y;
	}
	else if (!arg->c_count && arg->map[y][x] == 'E')
	{
		ft_exit(arg);
	}
}

int	ft_action(int key, t_arg *arg)
{
	int		x;
	int		y;

	ft_numb_of_elem_check(arg);
	x = arg->player_x;
	y = arg->player_y;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		ft_exit(arg);
	else
		return (0);
	mlx_clear_window(arg->mlx, arg->mlx_win);
	ft_map_mani(arg, x, y);
	ft_put_win(arg);
	return (0);
}
