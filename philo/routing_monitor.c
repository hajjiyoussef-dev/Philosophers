/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:10:44 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/26 10:48:32 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead_philo(t_params *par, int i)
{
	long	time_now;

	time_now = gettimes();
	if (time_now - par->philo[i].last_meal_time > par->time_to_die)
	{
		par->it_over = 1;
		printf("%ld %d died\n", time_now - par->start, (par->philo[i].id_philo
				+ 1));
		return (1);
	}
	return (0);
}

int	is_full_philo(t_params *par, int full_philo)
{
	if (full_philo == par->philo_nbr)
	{
		pthread_mutex_lock(par->death);
		par->it_over = 1;
		pthread_mutex_unlock(par->death);
		return (1);
	}
	return (0);
}

void	*routing_monitor(void *argv)
{
	t_params	*par;
	int			full_philo;
	int			i;

	par = (t_params *)argv;
	while (!par->it_over)
	{
		(1) && (full_philo = 0, i = 0);
		while (i < par->philo_nbr)
		{
			pthread_mutex_lock(par->death);
			if (is_dead_philo(par, i))
			{
				pthread_mutex_unlock(par->death);
				return (NULL);
			}
			if (par->philo[i].is_full)
				full_philo++;
			pthread_mutex_unlock(par->death);
			i++;
		}
		if (is_full_philo(par, full_philo))
			return (NULL);
	}
	return (NULL);
}
