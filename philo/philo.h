
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/time.h"
#include "pthread.h"

typedef struct	s_params
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
	long int	on_t;
	int	off;
	pthread_mutex_t	*fork;
}				t_params;

typedef struct	s_philo
{
	int	name;
	int	t_meal;
	int dead;
	int	loop;
	long int t_start;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t	tid;
	t_params	*data;

}				t_philo;

void	error_mut(void);
void    error_args(void);
void	error_thread(void);
int		ft_atoi(const char *str);

int 	init_philo(t_params *data, t_philo *philo);

void    thread_routine(void *actions);