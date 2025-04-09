/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 05:11:13 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/09 05:09:56 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc < 5 || argc > 6)
		return (write(2, "Please, enter the right amount of arguments\n", 45));
	if (parsing(&data, argv))
		return (1);
	init(&data, argv);
	init_philo(&data);
	start_run(&data);
	return (0);
}
