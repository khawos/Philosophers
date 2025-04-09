/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:36:04 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/09 06:27:29 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_philo(t_data *data, t_philo *philo)
{
	(void)philo;
	int	i;
	
	i = philo->id;
	pthread_mutex_lock(&data->forks[i]);
	pthread_mutex_unlock(&data->forks[i]);
}

void	*routine(void *philos)
{
	t_philo *philo = NULL;
	t_data *data;
	
	data = philo->data;
	philo = (t_philo *)philos;
	eat_philo(data, philo);
	return (NULL);
}

void	start_run(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_create(&data->philos[i].thread, NULL, routine, (void *)&data->philos[i]);
	i = 0;
	while (i < data->num_philos)
		pthread_join(data->philos[i++].thread, NULL);
}
