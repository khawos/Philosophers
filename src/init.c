/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:04:37 by amedenec          #+#    #+#             */
/*   Updated: 2025/03/24 07:14:14 by amedenec         ###   ########.fr       */
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

	d = 0;
	i = ft_atoi(argv[1]);
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	while (d < i)
	{
		data->philos[d].num_philos = i;
		data->philos[d].time_to_die = die;
		data->philos[d].time_to_eat = eat;
		data->philos[d++].time_to_sleep = sleep;
	}
}
