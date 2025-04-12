/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:44:49 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/12 18:32:17 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_think(t_philo *philo)
{
    ft_printf_status("is thinking", philo);
}

void ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->lf);
    pthread_mutex_lock(philo->rf);
    ft_printf_status("has taken a fork", philo);
}

void ft_eat(t_philo *philo)
{
    ft_printf_status("is eating ", philo);
    philo->last_meal_time = gettimes();
    philo->meals_count++;
    ft_usleep(philo->parms->time_to_eat);
}

void ft_put_down_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->lf);
    pthread_mutex_unlock(philo->rf);
}

void ft_sleep(t_philo *philo)
{
    ft_printf_status("is sleeping", philo);
    ft_usleep(philo->parms->time_to_sleep);
}
