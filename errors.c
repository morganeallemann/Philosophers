/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/07/27 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_args(void)
{
	printf("Error: Invalids arguments\n");
	exit (1);
}

void	error_mut(void)
{
	printf("Error: Mutex init failed\n");
	exit (1);
}

void	error_thread(void)
{
	printf("Error: Thread failed\n");
	exit (1);
}

void	error_malloc(void)
{
	printf("Error: Memory allocation failed\n");
	exit (1);
}
