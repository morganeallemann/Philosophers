/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, int time)
{
	long int	start;

	start = get_time();
	while (!philo_alive(philo->data, philo) && get_time() - start < time)
	{
		usleep(150);
	}
	return ;
}
 