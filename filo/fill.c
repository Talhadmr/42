#include "filo.h"

void fill_forks(t_data *data)
{
    int i;

    i = 0;
    while(i < data->number_of_philosopher)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
}

void fill_philos(t_data *data)
{
    int i;

    i = 0;
    while(i < data->number_of_philosopher)
    {
        data->philos[i].pos = i + 1;
        data->philos[i].posstr = ft_itoa(data->philos[i].pos);
        data->philos[i].rfork = i;
        data->philos[i].lfork = (i + 1) % data->number_of_philosopher;
        data->philos[i].data = data;
        i++;
    }
}

int ft_fill(t_data *data)
{
    data->philos = malloc(sizeof(t_filo)*data->number_of_philosopher);
    data->forks = malloc(sizeof(pthread_mutex_t)*data->number_of_philosopher);
    if (!data->philos || !data->forks )
        return (0);
    fill_philos(data);
    fill_forks(data);
    
    return (1);
}



int ft_arg(int ac, char **av, t_data *data)
{
    data->number_of_philosopher = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    data->exact_time = get_time();
    return (0);
}