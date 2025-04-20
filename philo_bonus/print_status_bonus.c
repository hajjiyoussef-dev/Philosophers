/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:11:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/20 21:21:30 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void ft_usleep(int time_to_sleep, t_philo *philo)
{
	if (philo->parms->time_to_die < time_to_sleep)
		usleep(philo->parms->time_to_die * 1000);
	else
		usleep(time_to_sleep * 1000);
}

void ft_print_status(const char *str, t_philo *philo)
{
	long time;

	sem_wait(philo->parms->death);
	time = (gettime() - philo->parms->start);
	if (philo->parms->it_over == 0)
		printf("%ld %d %s", time, (philo->id_philo + 1), str);
	sem_post(philo->parms->death);
		
}