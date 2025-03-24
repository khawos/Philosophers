#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_PHILO 200

typedef struct	s_philo
{
	pthread_t 		thread;
	int				id;
	int				num_philos;
	size_t			time_to_die;		
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	
}	t_philo;

typedef struct	s_data
{
	int				is_dead;
	t_philo			philos[MAX_PHILO];	
}	t_data;

// main
int		parsing(t_data *data, char **argv);
void	init(t_data *data, char **argv);
void	start_run(t_data *data);

// utils
int		ft_atoi(const char *str);

#endif
