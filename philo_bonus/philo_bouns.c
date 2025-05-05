/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bouns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:18:43 by yhajji            #+#    #+#             */
/*   Updated: 2025/05/05 00:52:46 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle1(t_params *par)
{
	printf("0 1 has taken a fork\n");
	usleep(par->time_to_die * 1000);
	printf("%d 1 died\n", (par->time_to_die));
	return ;
}

long	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

int	routine(t_philo *philo)
{
	pthread_t	monitor_id;

	if (philo->id_philo % 2 != 0)
		usleep(1000);
	pthread_create(&monitor_id, NULL, ft_routing_moniter, philo);
	while (1)
	{
		sem_wait(philo->parms->death);
		if (philo->parms->it_over == 1)
		{
			sem_post(philo->parms->death);
			break ;
		}
		sem_post(philo->parms->death);
		ft_take_forks(philo);
		ft_eat(philo);
		ft_put_down_forks(philo);
		ft_sleep(philo);
		if (philo->meals_count == philo->parms->max_philo_eat)
			exit(0);
		ft_think(philo);
	}
	pthread_join(monitor_id, NULL);
	return (0);
}

int	init_philo(t_params *par)
{
	int	i;

	i = 0;
	par->philo = malloc(sizeof(t_philo) * par->philo_nbr);
	if (!par->philo)
		return (1);
	while (i < par->philo_nbr)
	{
		par->philo[i].id_philo = i;
		par->philo[i].last_meal_time = gettime();
		par->philo[i].meals_count = 0;
		par->philo[i].parms = par;
		i++;
	}
	return (0);
}

int	philosophers(t_params *par)
{
	pid_t	pid;
	int		i;

	i = 0;
	par->start = gettime();
	if (init_philo(par))
		return (1);
	while (i < par->philo_nbr)
	{
		pid = fork();
		if (pid == -1)
			ft_error("fork", par, 1);
		else if (pid == 0)
		{
			routine(&(par->philo[i]));
			return (1);
		}
		par->philo[i].process_id = pid;
		i++;
	}
	ft_kill_process(par);
	free(par->philo);
	ft_clear(par);
	return (0);
}
