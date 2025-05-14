/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:11:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/05/15 00:46:52 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	help_philo(t_params *par)
{
	int	i;

	i = 0;
	while (i < par->philo_nbr)
	{
		sem_post(par->start_simul);
		i++;
	}
	ft_kill_process(par);
	free(par->philo);
	ft_clear(par);
}

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
