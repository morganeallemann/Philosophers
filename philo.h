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

typedef struct s_data
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_eat;
	int				ctrl_eat;
	int				ready;
	int				off;
	long int		on;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*death;
}				t_data;

typedef struct s_philo
{
	int				name;
	int				dead;
	int				loop;
	long int		thd_start;
	long int		meal_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		tid;
	t_data			*data;

}				t_philo;

void		error_mut(void);
void		error_args(void);
void		error_thread(void);
void		error_malloc(void);
void		print_text(t_philo *philo, char *type);
void		end_print(int status);
int			ft_atoi(char *str);

int			init_philo(t_data *data, t_philo *philo);
int			init_data(t_data *data, char **av);

int			process(t_data *data);
void		*thread_routine(void *actions);

int			philo_checker_eat(t_data *data, t_philo *philo, int i);
int			philo_alive(t_data *data, t_philo *philo);
void		philo_dead(t_philo *philo);

long int	get_time(void);
int			ft_usleep(int time);