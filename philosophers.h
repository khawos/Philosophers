#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# define MAX_PHILO 200

typedef struct s_data t_data;
//typedef struct s_monitoring t_monitoring;

typedef struct	s_monitoring
{
	pthread_t		thread;
}	t_monitoring;


typedef struct	s_philo
{
	pthread_t 		thread;
	int				id;
	int				num_philos;
	struct timeval	last_meal;
	size_t			time_to_die;		
	size_t			time_to_eat;
	size_t			time_to_sleep;
	t_data			*data;
}	t_philo;

typedef struct	s_data
{
	struct timeval	start_time; // ATTENTION
	int				is_dead;
	int				num_philos;
	pthread_mutex_t	stdin_mutex;
	pthread_mutex_t *forks;
	t_philo			philos[MAX_PHILO];
	t_monitoring	*monitoring;
}	t_data;

// main
int		parsing(t_data *data, char **argv);
void	init(t_data *data, char **argv);
void	init_philo(t_data *data);
void	start_run(t_data *data);

// utils
int		ft_atoi(const char *str);

#endif
