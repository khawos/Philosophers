#include "philosophers.h"

void	print_death(t_data *data, int id, long current)
{
	long	start;

	start = data->start_time.tv_sec * 1000
		+ data->start_time.tv_usec / 1000;
	pthread_mutex_lock(&data->stdin_mutex);
	printf("%ld %d died\n", current - start, id);
	pthread_mutex_unlock(&data->stdin_mutex);
}

void	print_time_take_right_fork(t_philo *philo)
{
	struct timeval	now;
	long ms_start;
	long ms_now;
	long elapsed;
	
	gettimeofday(&now, NULL);
	ms_start = philo->data->start_time.tv_sec * 1000 + philo->data->start_time.tv_usec / 1000;
	ms_now = now.tv_sec * 1000 + now.tv_usec / 1000;
	elapsed = ms_now - ms_start;
	if (1 == check_flag_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->stdin_mutex);
	printf("%ld %d has take the right fork\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->stdin_mutex);
}

void	print_time_take_left_fork(t_philo *philo)
{
	struct timeval	now;
	long ms_start;
	long ms_now;
	long elapsed;
	
	gettimeofday(&now, NULL);
	ms_start = philo->data->start_time.tv_sec * 1000 + philo->data->start_time.tv_usec / 1000;
	ms_now = now.tv_sec * 1000 + now.tv_usec / 1000;
	elapsed = ms_now - ms_start;
	if (1 == check_flag_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->stdin_mutex);
	printf("%ld %d has take the left fork\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->stdin_mutex);
}

void	print_time_is_eating(t_philo *philo)
{
	struct timeval	now;
	long ms_start;
	long ms_now;
	long elapsed;
	
	gettimeofday(&now, NULL);
	ms_start = philo->data->start_time.tv_sec * 1000 + philo->data->start_time.tv_usec / 1000;
	ms_now = now.tv_sec * 1000 + now.tv_usec / 1000;
	elapsed = ms_now - ms_start;
	if (1 == check_flag_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->stdin_mutex);
	printf("%ld %d is eating\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->stdin_mutex);
}