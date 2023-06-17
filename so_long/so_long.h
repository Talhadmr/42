/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:08:08 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 14:22:22 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_arg
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		line_count;
	void	*wall;
	void	*player;
	void	*img_exit;
	void	*colec;
	void	*back;
	int		player_x;
	int		player_y;
	int		p_count;
	int		e_count;
	int		c_count;
	int		row_len;
	char	**visited;
	char	**matrix;
	int		mat_y;
	int		mat_x;
	int		exit_i;
	int		exit_j;
	int		move;
}	t_arg;

void	ft_put(t_arg *arg, void *img, int x, int y);
void	ft_read_map(t_arg *arg, char *str);
int		ft_map_init(t_arg *arg, char *str);
void	ft_line_len(t_arg *arg, char *str);
int		ft_exit(t_arg *arg);
void	ft_numb_of_elem_check(t_arg *arg);
int		ft_action(int key, t_arg *arg);
int		ft_put_win(t_arg *arg);
int		ft_check_file_name(char *str);
int		ret_val(t_arg *arg);
int		ft_path(t_arg *arg, int i, int j);
void	map_exit_chack(int i, int j, t_arg *arg);
void	init_matrix(t_arg *arg);
void	ft_path_put(t_arg *arg, int result);
void	ft_matrix(t_arg *arg, char *str);
void	ft_visited(t_arg *arg, char *str);
void	ft_putchar(char c);
int		ft_check_player(t_arg *arg);
int		ft_check_exit(t_arg *arg);
int		ft_check_collec(t_arg *arg);
void	ft_last_check(t_arg *arg);

#endif
