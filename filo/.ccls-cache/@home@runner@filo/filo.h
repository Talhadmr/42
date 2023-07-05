#ifndef FILO_H
#define FILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_filo {
  pthread_t thread_id;
  int pos;
  char *posstr;
  int rfork;
  int lfork;
  unsigned long int last_ate;
  int ate_times;
  struct s_data *data;
} t_filo;

typedef struct s_data {
  int stop_condition;
  int				max_ate;
  int number_of_philosopher;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int number_of_times_each_philosopher_must_eat;
  unsigned long exact_time;
  t_filo *philos;
  pthread_mutex_t *forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
} t_data;

int ft_atoi(const char *str);
int ft_isntnum(int ac, char **av);
int ft_arg(int ac, char **av, t_data *data);
int ft_fill(t_data *data);
unsigned long get_time(void);
char *ft_itoa(int n);
void ft_run_pr(t_data *data);
void ft_sleep(unsigned long duration, t_data *data);
void ft_eat(t_filo *philo);
void philo_print(char *msg, t_filo *philo);

#endif