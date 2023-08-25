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

int init_philo(t_params *data, t_philo *philo)
{
    int i;

    i = 0;
    while(i < data->n_philo)
    {
        philo[i].name = i + 1;
        philo[i].t_meal = 0;
        philo[i].dead = 0;
        philo[i].loop = 0;
        philo[i].l_fork = &data->fork[i];
        philo[i].r_fork = philo[(i + 1) % data->n_philo].l_fork;
        philo[i].data = data;
        i++;
    }
    return (0);
}

int init_params(t_params *data, char **av)
{
    int     i;

    i = -1;
    data->n_philo = ft_atoi(av[1]);
    data->t_die = ft_atoi(av[2]);
    data->t_eat = ft_atoi(av[3]);
    data->t_sleep = ft_atoi(av[4]);
    data->on_t = 0;
    data->off = 0;
    if (av[5])
    {
        data->ctrl_eat = 1;
        data->n_eat = ft_atoi(av[5]);
        if (data->n_eat <= 0)
            return (1);
    }
    if (check_value(data) != 0)
        return (1);
    data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    while (++i < data->n_philo)
    {
        if (pthread_mutex_init(&data->fork[i], NULL) == -1)
            error_mut();
    }
    return (0);
}