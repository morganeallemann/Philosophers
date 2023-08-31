/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].r_fork = philo[(i + 1) % data->nb_philo].l_fork;
		if (pthread_create(&philo[i].tid, NULL, &thread_routine,
				&philo[i]) == -1)
			return (1);
		i++;
	}
	data->on = get_time();
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].thd_start = data->on;
		philo[i].meal_time = data->on;
		i++;
	}
	return (0);
}

int	thread_control(t_data *data, t_philo *philo)
{
	int	i;

	while (!data->off)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (philo_alive(data, philo) || philo_checker_eat(data, philo, i))
				data->off = 1;
			i++;
		}
	}
	if (data->ctrl_eat == 1 && data->max_eat == philo[data->nb_philo - 1].loop)
	{
		ft_usleep(5 * data->nb_philo);
		printf("Philosophers have eaten %d times\n", data->max_eat);
		return (0);
	}
	return (1);
}

void	end_process(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].tid, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_destroy(data->fork);
	pthread_mutex_destroy(data->death);
	free(data->fork);
	free(data->death);
	free(philo);
}

int	process(t_data *data)
{
	t_philo	*philo;
	int		status;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo || init_philo(data, philo) != 0)
		error_malloc();
	if (create_thread(data, philo) != 0)
		return (1);
	status = thread_control(data, philo);
	end_print(status);
	end_process(data, philo);
	return (0);
}
