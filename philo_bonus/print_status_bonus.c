/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:11:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/22 20:32:43 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void ft_usleep(int time_to_sleep, t_philo *philo)
{
	(void)philo;
	// if (philo->parms->time_to_die < time_to_sleep)
	// 	usleep(philo->parms->time_to_die * 1000);
	// else
	// 	usleep(time_to_sleep * 1000);
	long time = gettime();
	while (time_to_sleep > gettime() - time)
	{
		usleep(50);
	}
}

void ft_print_status(char *str, t_philo *philo)
{
	long time;

	sem_wait(philo->parms->death);
	time = (gettime() - philo->parms->start);
	sem_wait(philo->parms->write);
	if (!philo->parms->it_over)
		printf("%ld %d %s\n", time, (philo->id_philo + 1), str);
	sem_post(philo->parms->death);
	sem_post(philo->parms->write);
}
