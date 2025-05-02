/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:11:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/27 19:31:05 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(int time_to_sleep)
{
	long	time;

	time = gettime();
	while (time_to_sleep > gettime() - time)
	{
		usleep(50);
	}
}

void	ft_print_status(char *str, t_philo *philo)
{
	long	time;

	sem_wait(philo->parms->death);
	time = (gettime() - philo->parms->start);
	sem_wait(philo->parms->write);
	if (!philo->parms->it_over)
		printf("%ld %d %s\n", time, (philo->id_philo + 1), str);
	sem_post(philo->parms->death);
	sem_post(philo->parms->write);
}
