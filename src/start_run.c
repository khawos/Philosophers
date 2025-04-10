/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:36:04 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/10 03:51:38 by amedenec         ###   ########.fr       */
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
	usleep(1000000);
	print_time(philo);
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

void	*routine_monitoring(void *data)
{
	t_data *data_monitor;
	
	data_monitor = (t_data *)data;
	pthread_mutex_lock(&data_monitor->stdin_mutex);
	printf("Bonjour, je monitor\n");
	pthread_mutex_unlock(&data_monitor->stdin_mutex);
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
