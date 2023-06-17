/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:08:05 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 14:15:23 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(t_arg *arg, void *img, int x, int y)
{
	mlx_put_image_to_window(arg->mlx, arg->mlx_win, img, 64 * x, 64 * y);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
