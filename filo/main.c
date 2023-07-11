/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:29:20 by tdemir            #+#    #+#             */
/*   Updated: 2023/07/06 16:33:56 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		write (1, "error\n", 6);
		exit (1);
	}
	if (!ft_isntnum(ac, av))
	{
		write (1, "error\n", 6);
		exit (1);
	}
	ft_arg (ac, av, &data);
	if (!ft_fill(&data))
	{
		write (1, "error\n", 6);
		exit (1);
	}
	ft_run_pr(&data);
}
