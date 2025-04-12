#include "philosophers.h"

int     check_death(t_data *data, int i);

void	*routine_monitoring(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	usleep_precise_ms(1);
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(data, i))
			{
				pthread_mutex_lock(&data->mutex_check_death);
				data->is_dead = 1;
				pthread_mutex_unlock(&data->mutex_check_death);
				return (NULL);
			}
			i++;
		}
		usleep_precise_ms(1); // pour ne pas spam le cpu
	}
	return (NULL);
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