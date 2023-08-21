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

void    error_args(void)
{
	printf("Invalids arguments\n");
	exit (1);
}

void	error_mut(void)
{
	printf("Mutex init error\n");
	exit (1);
}

void	error_thread(void)
{
	printf("Error: Thread failed\n");
	exit (1);
}

int	ft_atoi(const char *str)
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