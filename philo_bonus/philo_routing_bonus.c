/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:50:19 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/20 21:08:39 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void ft_take_forks(t_philo *philo)
{
	if (philo->id_philo % 2 == 0)
	{
		sem_wait(philo->lf);
		ft_print_status("has taken a fork", philo);
		sem_wait(philo->rf);
		ft_print_status("has taken a fork", philo);
	}
	else 
	{
		sem_wait(philo->rf);
		ft_print_status("has taken a fork", philo);
		sem_wait(philo->lf);
		ft_print_status("has taken a fork", philo);
	}
}

void ft_eat(t_philo *philo)
{
	sem_wait(philo->parms->death);
	philo->last_meal_time = gettime();
	philo->meals_count++;
	if (philo->meals_count == philo->parms->max_philo_eat)
		philo->is_full = true;
	sem_post(philo->parms->death);
	ft_print_status("is eating", philo);
	ft_usleep(philo->parms->time_to_eat, philo);
}
void ft_put_down_forks(t_philo *philo)
{
	sem_post(philo->lf);
	sem_post(philo->rf);
}

void ft_sleep(t_philo *philo)
{
	ft_printf_status("is sleeping", philo);
	ft_usleep(philo->parms->time_to_sleep, philo);
}