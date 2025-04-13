/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:04:37 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/13 04:42:31 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_data *data, char **argv)
{
	int	i;
	int	d;
	int	die;
	int	eat;
	int	sleep;
	int	max_meal;

	d = 0;
	i = ft_atoi(argv[1]);
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	max_meal = ft_atoi(argv[5]);
	data->is_dead = 0;
	data->max_meal = max_meal;
	while (d < i)
	{
		data->philos[d].id = d;
		data->num_philos = i;
		data->philos[d].num_philos = i;
		data->philos[d].time_to_die = die;
		data->philos[d].time_to_eat = eat;
		data->philos[d].time_to_sleep = sleep;
		data->philos[d].data = data;
		data->philos[d++].num_of_meal = 0;
	}
}

void	init_philo(t_data *data)
{
	t_monitoring *monitoring;
	int	i;

	monitoring = NULL;
	i = 0;
	monitoring = malloc(sizeof(t_monitoring));
	if (!monitoring)
	{
		// TODO
	}
	pthread_mutex_init(&data->stdin_mutex, NULL);
	pthread_mutex_init(&data->mutex_check_last_meal, NULL);
	pthread_mutex_init(&data->mutex_check_death, NULL);
	pthread_mutex_init(&data->mutex_num_meal, NULL);
	data->forks = malloc((sizeof(pthread_mutex_t)) * data->num_philos);
	if (!data->forks)
	{
		// TODO
	}
	gettimeofday(&data->start_time, NULL); // sauvegarde le temps
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i++], NULL);
	}
	data->monitoring = monitoring;
}
