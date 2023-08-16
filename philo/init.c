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

int check_value(t_params *data)
{
    if (data->n_philo <= 0 || data->t_die <= 0 || data->t_eat <= 0
        || data->t_sleep <= 0)
        return (1);
    else
        return (0);
}

int init_params(t_params *data, char **av)
{
    int i;

    i = 0;
    data->n_philo = ft_atoi(av[1]);
    data->t_die = ft_atoi(av[2]);
    data->t_eat = ft_atoi(av[3]);
    data->t_sleep = ft_atoi(av[4]);
    if (av[5])
    {
        data->n_t_eat = ft_atoi(av[5]);
        if (data->n_t_eat <= 0)
            error_args();
    }
    if (check_value(&data) != 0)
        error_args();
    while (i < data->n_philo)
    {
        if (pthread_mutex_init(&data->n_fork[i], NULL) == -1)
            error_mut();
        i++;
    }
}