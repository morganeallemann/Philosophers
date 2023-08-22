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

void    philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork)
	print_text(&philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	print_text(&philo, FORK);
	philo->t_meal = get_time();
	usleep(philo->data->t_eat * 1000);
	print_text(&philo, EAT);
	philo->loop++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
} 

void    philo_sleep(t_philo *philo)
{

}

void    philo_think(t_philo *philo)
{
	
}

void    thread_routine(void *actions)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)actions;
	if (philo.name % 2 == 0)
		usleep(500);
	while (!philo->data->off)
	{
		philo_eat(&philo);
		philo_sleep(&philo);
		philo_think(&philo);
	}

}