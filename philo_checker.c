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

int	philo_max_eat(t_params *data, t_philo *philo, int i)
{
	if (data->ctrl_eat == 1 && i == data->n_philo && data->n_eat == philo->loop)
		return (1);
	else
		return (0);
}

int	philo_alive(t_params *data, t_philo *philo)
{
	int	time;

	time = get_time();
	if (time >= data->t_die)
	{
		philo_dead(philo);
		return (1);
	}
	else
		return (0);
}