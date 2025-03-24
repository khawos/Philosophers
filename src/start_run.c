/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:36:04 by amedenec          #+#    #+#             */
/*   Updated: 2025/03/24 07:20:50 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	printf("le temps pour mourir est de: %zu\n", philo->time_to_die);
	return (NULL);
}

void	start_run(t_data *data)
{
	pthread_create(&data->philos[0].thread, NULL, routine, (void *)&data->philos[0]);
	pthread_create(&data->philos[1].thread, NULL, routine, (void *)&data->philos[1]);
	pthread_join(data->philos[0].thread, NULL);
	pthread_join(data->philos[1].thread, NULL);
}
