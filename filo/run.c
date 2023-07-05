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
		while (data->number_of_times_each_philosopher_must_eat && i < data->number_of_philosopher
			&& philo[i].ate_times >= data->number_of_times_each_philosopher_must_eat)
			i++;
		data->max_ate = (i == data->number_of_philosopher);
	}
}

void *my_func(
    void *pr) // burası t_data tipinde bir şeyle değiştirelecek denenenenenenen
{
  t_filo *philo;
  t_data *data;
  philo = (t_filo *)pr;
  data = philo->data;
  if (philo->pos % 2 && data->number_of_philosopher > 1)
    ft_sleep(data->time_to_eat / 50, data);
  while (!data->max_ate && !data->stop_condition) {
    ft_eat(philo);
    philo_print("is sleeping", philo);
    ft_sleep(data->time_to_sleep, data);
    philo_print("is thinking", philo);
  }
  return (NULL);
}

void ft_run_pr(t_data *data) {
  int i;

  i = 0;
  while (i < data->number_of_philosopher) {
    pthread_create(&data->philos[i].thread_id, NULL, my_func,
                   &(data->philos[i]));
    i++;
  }
  philo_dead(data, data->philos);
  i = 0;
  while (i < data->number_of_philosopher)
  {
      pthread_join(data->philos[i].thread_id, NULL);
      i++;
  }
}

