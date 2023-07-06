/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:29:58 by tdemir            #+#    #+#             */
/*   Updated: 2023/07/05 19:27:13 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	philo_dead(t_data *data, t_filo *philo)
{
	int	i;

	while (!data->max_ate)
	{
		i = -1;
		while (++i < data->number_of_philosopher && !data->stop_condition)
		{
			pthread_mutex_lock(&data->meal);
			if ((get_time() - philo[i].last_ate) >= data->time_to_die)
			{
				philo_print("died", &philo[i]);
				data->stop_condition = 1;
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (data->stop_condition)
			break ;
		i = 0;
		while (data->number_of_times_each_philosopher_must_eat
			&& i < data->number_of_philosopher
			&& philo[i].ate_times
			>= data->number_of_times_each_philosopher_must_eat)
			i++;
		data->max_ate = (i == data->number_of_philosopher);
	}
}

void	*my_func(void *pr)
{
	t_filo	*philo;
	t_data	*data;

	philo = (t_filo *)pr;
	data = philo->data;
	if (philo->pos % 2 && data->number_of_philosopher > 1)
		ft_sleep(data->time_to_eat / 20, data);
	while (!data->max_ate && !data->stop_condition)
	{
		ft_eat(philo);
		philo_print("is sleeping", philo);
		ft_sleep(data->time_to_sleep, data);
		philo_print("is thinking", philo);
	}
	return (NULL);
}

void	ft_run_pr(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosopher)
	{
		pthread_create(&data->philos[i].thread_id,
			NULL, my_func, &(data->philos[i]));
	}
	philo_dead(data, data->philos);
	i = -1;
	if (data->number_of_philosopher == 1)
		pthread_detach(data->philos[0].thread_id);
	while (++i < data->number_of_philosopher)
		pthread_join(data->philos[i].thread_id, NULL);
	i = -1;
	while (++i < data->number_of_philosopher)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->meal);
	i = -1;
	while (++i < data->number_of_philosopher)
		free(data->philos[i].posstr);
	free(data->philos);
	free(data->forks);
}
