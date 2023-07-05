#include "filo.h"

void *my_func(void *pr) //burası t_data tipinde bir şeyle değiştirelecek denenenenenenen
{
    printf("kdsvk\n");
    t_filo *philo;
    t_data *data;
    philo = (t_filo *)pr;
    data = philo->data;
    printf("%d\n", data->number_of_philosopher);
    
    
    /*
    t_filo *philo;
    t_data *data;
    int i;

    i = 0;
    philo = (t_philo *)params;
    data = philo->data
    */
    return(NULL);
}

void ft_run_pr(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosopher)
    {
        pthread_create(&data->philos[i].thread_id, NULL, my_func, &(data->philos[i]));
        i++;
    }
}