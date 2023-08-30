/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] < str2[i])
			return (-1);
		if (str1[i] > str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_text(t_philo *philo, char *type)
{
	pthread_mutex_lock(philo->data->death);
	if (philo->data->off)
	{
		pthread_mutex_unlock(philo->data->death);
		return ;
	}
	if (ft_strncmp("fork", type, 4) == 0)
		printf("%ldms %d has taken a fork\n", get_time() - philo->thd_start,
			philo->name);
	else if (ft_strncmp("eat", type, 3) == 0)
		printf("%ldms %d is eating\n", get_time() - philo->thd_start,
			philo->name);
	else if (ft_strncmp("sleep", type, 5) == 0)
		printf("%ldms %d is sleeping\n", get_time() - philo->thd_start,
			philo->name);
	else if (ft_strncmp("think", type, 5) == 0)
		printf("%ldms %d is thinking\n", get_time() - philo->thd_start,
			philo->name);
	else if (ft_strncmp("dead", type, 4) == 0)
		printf("%ldms %d is died\n", get_time() - philo->thd_start,
			philo->name);
	pthread_mutex_unlock(philo->data->death);
}

void	end_print(int status)
{
	if (!status)
		printf("All philosophers are alive !\n");
	else
		printf("A philosopher died :-( \n");
}

int	ft_atoi(char *str)
{
	long	resultat;
	int		i;
	int		a;

	resultat = 0;
	i = 0;
	a = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = (resultat * 10) + (str[i] - '0');
		i++;
	}
	return (resultat * a);
}
