/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:10:43 by tdemir            #+#    #+#             */
/*   Updated: 2022/12/23 13:41:04 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_nbr(int num)
{
	char	a;

	if (num < 10)
	{
		a = num + '0';
		write (1, &a, 1);
	}
	else if (num > 9)
	{
		put_nbr(num / 10);
		put_nbr(num % 10);
	}
}

void	my_handler(int sign)
{
	static int	bit;
	static int	set;

	if (sign == SIGUSR1)
		set += 1 << bit;
	if (bit == 7)
	{
		write (1, &set, 1);
		bit = 0;
		set = 0;
	}
	else
		bit++;
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 1)
	{
		pid = getpid();
		put_nbr (pid);
		write (1, "\n", 1);
		signal (SIGUSR1, my_handler);
		signal (SIGUSR2, my_handler);
		while (1)
			pause();
	}
	else
		write (1, "please enter just one argument", 30);
}
