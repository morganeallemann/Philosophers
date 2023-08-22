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

int create_thread(t_params *data, t_philo *philo)
{
    int i;

    i = 0;
    while(i < data->n_philo)
    {
        if (pthread_create(&philo[i].tid, NULL, &thread_routine, &philo[i]))
            return (1);
        i++;
    }
    data->on_t = get_time();
    if (!data->on_t)
    {
        printf("Error: time setup failed\n");
        exit (1);
    }
    i = 0;
    while (i < data->n_philo)
    {
        philo[i].t_start = data->on_t;
        i++;
    }
    return (0);
}

int process(t_params *data)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * data->n_philo);
    if (!philo || init_philo(data, philo) != 0)
        return (1);
    if (create_thread(data, philo) != 0)
        return (1);
}