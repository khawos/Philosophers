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
	size_t			num_of_meal;
	t_data			*data;
}	t_philo;

typedef struct	s_data
{
	struct timeval	start_time; // ATTENTION
	int				is_dead;
	int				num_philos;
	size_t				max_meal;
	pthread_mutex_t	stdin_mutex;
	pthread_mutex_t	mutex_check_last_meal;
	pthread_mutex_t	mutex_num_meal;
	pthread_mutex_t	mutex_check_death;
	pthread_mutex_t *forks;
	t_philo			philos[MAX_PHILO];
	t_monitoring	*monitoring;
}	t_data;

// main
int		parsing(t_data *data, char **argv);
void	init(t_data *data, char **argv);
void	init_philo(t_data *data);
void	start_run(t_data *data);
void	print_death(t_data *data, int id, long current);

// utils
int		ft_atoi(const char *str);

// monitoring

void	*routine_monitoring(void *arg);
//int		check_death(t_data *data, int i);
int	check_meal(t_data *data);

// start_run
int	check_flag_dead(t_philo *philo);

// print_mili
void	print_time_is_eating(t_philo *philo);
void	print_time_is_sleeping(t_philo *philo);
void	print_time_is_thinking(t_philo *philo);
void	print_time_take_fork(t_philo *philo);
void	print_death(t_data *data, int id, long current);
void	usleep_precise_ms(long nb);

#endif
