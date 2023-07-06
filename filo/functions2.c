/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:29:49 by tdemir            #+#    #+#             */
/*   Updated: 2023/07/05 18:29:50 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	philo_print(char *msg, t_filo *philo)
{
	char	*timestamp;

	timestamp = ft_itoa(get_time() - philo->data->exact_time);
	pthread_mutex_lock(&philo->data->writing);
	if (!philo->data->stop_condition && !philo->data->max_ate)
		printf("%s %s %s\n", timestamp, philo->posstr, msg);
	pthread_mutex_unlock(&philo->data->writing);
	free(timestamp);
}

void	ft_sleep(unsigned long duration, t_data *data)
{
	unsigned long	start;

	start = get_time();
	while (!data->stop_condition)
	{
		if (get_time() - start >= duration)
			break ;
		usleep(data->number_of_philosopher * 2);
	}
}

void	ft_eat(t_filo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lfork]);
	philo_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[philo->rfork]);
	philo_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->meal);
	philo_print("is eating", philo);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->data->meal);
	ft_sleep(philo->data->time_to_eat, philo->data);
	philo->ate_times++;
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
}

static	long	digit(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*mystr;
	int		a;
	long	nb;

	nb = n;
	a = digit(nb);
	mystr = (char *)malloc(a + 1);
	if (!mystr)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		mystr[0] = '-';
	}
	mystr[a] = '\0';
	a--;
	while ((n < 0) <= a)
	{
		mystr[a] = (nb % 10) + 48;
		nb /= 10;
		a--;
	}
	return (mystr);
}
