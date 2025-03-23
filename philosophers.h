#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




typedef struct	s_data
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		max_time_eat;
	
}		t_data;

/*typedef struct	s_philo
{
	int				id;
	pthread_t 		thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_data			*data;
}t_philo;*/

int		parsing(t_data *data, char **argv);
void	init(t_data *data);

// utils
int		ft_atoi(const char *str);

#endif
