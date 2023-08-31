/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_text(philo, "fork");
	pthread_mutex_lock(philo->r_fork);
	print_text(philo, "fork");
	pthread_mutex_lock(philo->data->death);
	philo->meal_time = get_time();
	pthread_mutex_unlock(philo->data->death);
	ft_usleep(philo->data->t_eat);
	print_text(philo, "eat");
	pthread_mutex_lock(philo->data->death);
	philo->loop++;
	pthread_mutex_unlock(philo->data->death);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep_and_think(t_philo *philo)
{
	ft_usleep(philo->data->t_sleep);
	print_text(philo, "sleep");
	print_text(philo, "think");
}

void	philo_dead(t_philo *philo)
{
	print_text(philo, "dead");
	philo->dead = 1;
	pthread_mutex_lock(philo->data->death);
	philo->data->off = 1;
	pthread_mutex_unlock(philo->data->death);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*thread_routine(void *actions)
{
	t_philo	*philo;

	philo = (t_philo *)actions;
	if (philo->name % 2 == 0)
		usleep(500);
	pthread_mutex_lock(philo->data->death);
	while (!philo->data->off)
	{
		pthread_mutex_unlock(philo->data->death);
		philo_eat(philo);
		philo_sleep_and_think(philo);
		pthread_mutex_lock(philo->data->death);
	}
	pthread_mutex_unlock(philo->data->death);
	return (NULL);
}
