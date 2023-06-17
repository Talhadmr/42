/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:44 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/12 12:42:28 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac != 2)
	{
		write(1, "missing arguman error\n", 22);
		exit (1);
	}
	if (!ft_check_file_name (av[1]))
	{
		write (1, "file name error\n", 16);
		exit (1);
	}
	ft_map_init (&arg, av[1]);
	return (0);
}
