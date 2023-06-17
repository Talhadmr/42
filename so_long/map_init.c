/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:58 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 13:50:53 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_xpm(t_arg *arg)
{
	int	x;
	int	y;

	arg->back = mlx_xpm_file_to_image(arg->mlx, "./img/back.xpm", &x, &y);
	arg->colec = mlx_xpm_file_to_image(arg->mlx, "./img/collec.xpm", &x, &y);
	arg->img_exit = mlx_xpm_file_to_image(arg->mlx, "./img/exit.xpm", &x, &y);
	arg->player = mlx_xpm_file_to_image(arg->mlx, "./img/player.xpm", &x, &y);
	arg->wall = mlx_xpm_file_to_image(arg->mlx, "./img/wall11.xpm", &x, &y);
	if (!arg->back || !arg->colec || !arg->wall || !arg->player)
		return (1);
	return (0);
}

int	ft_put_win(t_arg *arg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (arg->map[y][x])
	{
		if (arg->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (arg->map[y][x] == 'P')
			ft_put (arg, arg->player, x, y);
		if (arg->map[y][x] == 'E')
			ft_put (arg, arg->img_exit, x, y);
		if (arg->map[y][x] == '1')
			ft_put(arg, arg->wall, x, y);
		if (arg->map[y][x] == 'C')
			ft_put(arg, arg->colec, x, y);
		if (arg->map[y][x] == '0')
			ft_put(arg, arg->back, x, y);
		x++;
	}
	return (0);
}

int	ft_map_init(t_arg *arg, char *str)
{
	ft_read_map (arg, str);
	arg->move = 0;
	init_matrix (arg);
	if (!ret_val (arg))
	{
		write (1, "map border error\n", 17);
		exit (1);
	}
	ft_last_check (arg);
	arg->mlx = mlx_init ();
	arg->mlx_win = mlx_new_window(arg->mlx, 64 * (ft_strlen(arg->map[0]) - 1), \
			64 * arg->line_count, "SO_LONG");
	if (!arg->mlx || !arg->mlx_win || ft_create_xpm (arg))
	{
		write (1, "invalid map\n", 12);
		exit (1);
	}
	ft_put_win (arg);
	mlx_hook (arg->mlx_win, 2, 1L << 2, ft_action, arg);
	mlx_hook (arg->mlx_win, 17, 1L << 2, ft_exit, arg);
	mlx_loop (arg->mlx);
	return (0);
}
