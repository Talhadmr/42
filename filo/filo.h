#ifndef FILO_H
# define FILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

int	ft_atoi(const char *str);
int ft_isntnum(int ac , char **av);

typedef struct s_data
{
    int number_of_philosopher;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;  
    pthread_mutex_t	*forks;
}           t_data;

#endif