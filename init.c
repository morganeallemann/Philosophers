/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_value(t_data *data)
{
	if (data->nb_philo <= 0 || data->t_die <= 0 || data->t_eat <= 0
		|| data->t_sleep <= 0)
		return (1);
	else
		return (0);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= 0 && av[i][j] <= 9))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].name = i + 1;
		philo[i].meal_time = 0;
		philo[i].dead = 0;
		philo[i].loop = 0;
		philo[i].thd_start = 0;
		philo[i].l_fork = &data->fork[i];
		philo[i].r_fork = 0;
		philo[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (check_arg != 0)
		return (1);
	data->fork = 0;
	data->death = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (1);
	data->death = malloc(sizeof(pthread_mutex_t));
	if (!data->death)
		return (1);
	if (pthread_mutex_init(data->death, NULL) == -1)
		error_mut();
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) == -1)
			error_mut();
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->max_eat = -2;
	data->ctrl_eat = 0;
	data->ready = 0;
	data->on = 0;
	data->off = 0;
	if (av[5])
	{
		data->ctrl_eat = 1;
		data->max_eat = ft_atoi(av[5]);
	}
	if (check_value(data) != 0)
		return (1);
	if (init_mutex(data) != 0)
		error_malloc();
	return (0);
}
