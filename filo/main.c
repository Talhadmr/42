#include "filo.h"

int ft_init(int ac, char **av, t_data *data)
{
    data->number_of_philosopher = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    return (0);
}
int main(int ac, char **av)
{
    t_data data;

    if(ac < 5 || ac > 6)
        write(1, "error\n", 6);
    if(!ft_isntnum(ac, av))
        write(1, "error\n", 6);
    ft_init(ac, av, &data);
        
}
