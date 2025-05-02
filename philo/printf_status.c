/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:05:45 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/24 18:05:05 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time_to_sleep, t_philo *philo)
{
	long	time;

	time = gettimes();
	if (philo->parms->time_to_die < time_to_sleep)
	{
		while (philo->parms->time_to_die > gettimes() - time)
		{
			usleep(50);
		}
	}
	else
	{
		while (time_to_sleep > gettimes() - time)
		{
			usleep(50);
		}
	}
}

void	ft_printf_status(char *msg, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->parms->death);
	time = (gettimes() - philo->parms->start);
	if (!philo->parms->it_over)
		printf("%ld %d %s\n", time, (philo->id_philo + 1), msg);
	pthread_mutex_unlock(philo->parms->death);
}
