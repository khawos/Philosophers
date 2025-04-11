/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:36:04 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/11 06:04:43 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_time(t_philo *philo)
{
	struct timeval	now;
	long ms_start;
	long ms_now;
	long elapsed;
	
	gettimeofday(&now, NULL);
	ms_start = philo->data->start_time.tv_sec * 1000 + philo->data->start_time.tv_usec / 1000;
	ms_now = now.tv_sec * 1000 + now.tv_usec / 1000;
	elapsed = ms_now - ms_start;
	pthread_mutex_lock(&philo->data->stdin_mutex);
	printf("%ld %d is eating\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->stdin_mutex);
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_check_last_meal);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->data->mutex_check_last_meal);
	print_time(philo);
	usleep(philo->time_to_eat * 1000);
}

void	*routine(void *philos)
{
	t_philo *philo = NULL;
	
	philo = (t_philo *)philos;
	eat_philo(philo);
	//sleep_philo(philo);
	//think_philo(philo);
	return (NULL);
}


void	print_death(t_data *data, int id, long current)
{
	long	start;

	start = data->start_time.tv_sec * 1000
		+ data->start_time.tv_usec / 1000;
	pthread_mutex_lock(&data->stdin_mutex);
	printf("%ld %d died\n", current - start, id);
	pthread_mutex_unlock(&data->stdin_mutex);
}

int	check_death(t_data *data, int i)
{
	struct timeval	now;
	size_t			last;
	size_t			current;
	size_t			elapsed;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&data->mutex_check_last_meal);
	last = data->philos[i].last_meal.tv_sec * 1000
		+ data->philos[i].last_meal.tv_usec / 1000;
	pthread_mutex_unlock(&data->mutex_check_last_meal);
	current = now.tv_sec * 1000 + now.tv_usec / 1000;
	elapsed = current - last;
	if (elapsed > data->philos[i].time_to_die)
	{
		print_death(data, data->philos[i].id, current);
		return (1);
	}
	return (0);
}

void	*routine_monitoring(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	usleep(100);
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(data, i))
			{
				data->is_dead = 1;
				return (NULL);
			}
			i++;
		}
		usleep(1); // pour ne pas spam le cpu
	}
	return (NULL);
}

void	start_run(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_create(&data->philos[i].thread, NULL, routine, (void *)&data->philos[i]);
	pthread_create(&data->monitoring->thread, NULL, routine_monitoring, (void *)data);
		i = 0;
	while (i < data->num_philos)
		pthread_join(data->philos[i++].thread, NULL);
	pthread_join(data->monitoring->thread, NULL);
}
