/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:08:03 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 14:06:32 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rectangle_check(t_arg *arg)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(arg->map[0]);
	y = 0;
	while (y < arg->line_count)
	{
		x = 0;
		while (arg->map[y] && arg->map[y][x] != '\n' && \
				x < (int)(ft_strlen(arg->map[y])))
			x++;
		if (x != len - 1)
			return (1);
		y++;
	}
	return (0);
}

void	ft_line_len(t_arg *arg, char *str)
{
	int		fd;
	int		len;
	char	c;

	fd = open(str, O_RDONLY);
	len = 0;
	while (read (fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	close (fd);
	arg->map = malloc (sizeof(char *) * (len + 1));
	arg->matrix = malloc (sizeof(char *) * (len + 1));
	arg->visited = malloc (sizeof(char *) * (len + 1));
	arg->matrix[len + 1] = NULL;
	arg->visited[len + 1] = NULL;
	arg->map[len + 1] = NULL;
	arg->line_count = len;
}

void	ft_read_map(t_arg *arg, char *str)
{
	int	fd;
	int	i;

	ft_line_len (arg, str);
	i = 0;
	fd = open(str, O_RDONLY);
	arg->map[i] = get_next_line(fd);
	arg->row_len = ft_strlen(arg->map[i]);
	arg->mat_x = arg->row_len -1;
	arg->mat_y = arg->line_count;
	while (arg->map[i])
	{
		i++;
		arg->map[i] = get_next_line(fd);
	}
	close(fd);
	if (ft_rectangle_check(arg))
	{
		write (1, "invalid map\n", 12);
		exit (1);
	}
	ft_matrix(arg, str);
}

void	ft_matrix(t_arg *arg, char *str)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(str, O_RDONLY);
	arg->matrix[i] = get_next_line(fd);
	while (arg->map[i])
	{
		i++;
		arg->matrix[i] = get_next_line(fd);
	}
	close (fd);
	ft_visited(arg, str);
}

void	ft_visited(t_arg *arg, char *str)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(str, O_RDONLY);
	arg->visited[i] = get_next_line(fd);
	while (arg->map[i])
	{
		i++;
		arg->visited[i] = get_next_line(fd);
	}
	close(fd);
}
