#ifndef FILO_H
# define FILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>



typedef struct s_filo
{
    pthread_t	thread_id;
    int pos;
    int rfork;
    int lfork;
}       t_filo;

typedef struct s_data
{
    int number_of_philosopher;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    unsigned long exact_time;
    t_filo *philos;  
    pthread_mutex_t	*forks;
}           t_data;

int	ft_atoi(const char *str);
int ft_isntnum(int ac , char **av);
int ft_init(int ac, char **av, t_data *data);
int ft_fill(t_data *data);
unsigned long	get_time(void);


#endif