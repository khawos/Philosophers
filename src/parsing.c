/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:31:00 by amedenec          #+#    #+#             */
/*   Updated: 2025/03/23 08:22:52 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_num(char	*str)
{
	while (*str)
	{
		if (*str++ == '+')
			continue;
		if (*str <= '0' || *str >= '9')
			return (1);
		str++;
	}
	return (0);
}


int	parsing(t_data *data, char **argv)
{
	(void)data;
	(void)argv;
	
	if (ft_atoi(argv[1]) <= 0 || is_num(argv[1])) // mettre a 200 le max de philo
		return (write(2, "please enter valids arguments\n", 31)); // verifier l orthographe
	if (ft_atoi(argv[2]) <= 0 || is_num(argv[2]))
		return (write(2, "please enter valids arguments\n", 31));
	if (ft_atoi(argv[3]) <= 0 || is_num(argv[3]))
		return (write(2, "please enter valids arguments\n", 31));
	if (ft_atoi(argv[4]) <= 0 || is_num(argv[4]))
		return (write(2, "please enter valids arguments\n", 31));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || is_num(argv[5])))
		return (write(2, "please enter valids arguments\n", 31));
	return (0);
}
