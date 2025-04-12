/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:36:04 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/12 04:39:14 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_flag_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_check_death);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_check_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex_check_death);
	return (0);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_check_last_meal);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->data->mutex_check_last_meal);
}

void	take_forks(t_philo *philo)
{
	int	left = philo->id;
	int	right = (philo->id + 1) % philo->num_philos;

	if (left < right)
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		print_time_take_left_fork(philo);
		pthread_mutex_lock(&philo->data->forks[right]);
		print_time_take_right_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		print_time_take_right_fork(philo);
		pthread_mutex_lock(&philo->data->forks[left]);
		print_time_take_left_fork(philo);
	}
}

void	drop_forks(t_philo *philo)
{
	int	left = philo->id;
	int	right = (philo->id + 1) % philo->num_philos;

	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
}


void	eat_philo(t_philo *philo)
{
	take_forks(philo);
	set_last_meal(philo);
	print_time_is_eating(philo);
	usleep(philo->time_to_eat * 1000);
	drop_forks(philo);
}

void	*routine(void *philos)
{
	t_philo *philo = NULL;
	
	philo = (t_philo *)philos;
	set_last_meal(philo);
	while (0 == check_flag_dead(philo))
	{
		eat_philo(philo);		
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}


void	start_run(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, routine, (void *)&data->philos[i]);		
	}
	pthread_create(&data->monitoring->thread, NULL, routine_monitoring, (void *)data);
		i = 0;
	while (i < data->num_philos)
		pthread_join(data->philos[i++].thread, NULL);
	pthread_join(data->monitoring->thread, NULL);
}
