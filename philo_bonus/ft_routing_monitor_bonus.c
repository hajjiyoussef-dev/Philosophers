/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routing_monitor_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:11:58 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/26 11:38:39 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_routing_moniter(void *argv)
{
	t_philo	*philo;
	int		i;
	long	time;

	philo = (t_philo *)argv;
	while (1)
	{
		i = 0;
		time = gettime();
		sem_wait(philo->parms->death);
		if (time - philo->last_meal_time > philo->parms->time_to_die)
		{
			philo->parms->it_over = 1;
			sem_wait(philo->parms->write);
			printf("%ld %d died\n", (time - philo->parms->start),
				(philo->id_philo + 1));
			sem_post(philo->parms->death);
			exit(1);
		}
		sem_post(philo->parms->death);
		i++;
		usleep(2000);
	}
	return (NULL);
}
