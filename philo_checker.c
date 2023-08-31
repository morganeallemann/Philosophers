/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_checker_eat(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(philo->data->death);
	if (data->ctrl_eat == 1 && i == data->nb_philo - 1
		&& data->max_eat == philo->loop)
	{
		pthread_mutex_unlock(philo->data->death);
		return (ft_usleep(300));
	}
	else
	{
		pthread_mutex_unlock(philo->data->death);
		return (0);
	}
}

int	philo_alive(t_data *data, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(data->death);
	time = get_time() - philo->meal_time;
	if (time >= data->t_die)
	{
		pthread_mutex_unlock(data->death);
		philo_dead(philo);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(data->death);
		return (0);
	}
}
