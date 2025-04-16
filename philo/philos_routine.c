/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:44:49 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/16 22:24:04 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_think(t_philo *philo)
{
    ft_printf_status("is thinking", philo);
}

void ft_take_forks(t_philo *philo)
{
    if (philo->id_philo % 2 == 0)
    {
        pthread_mutex_lock(philo->lf);
        ft_printf_status("has taken a fork", philo);
        pthread_mutex_lock(philo->rf);
        ft_printf_status("has taken a fork", philo);
    }
    else
    {
        pthread_mutex_lock(philo->rf);
        ft_printf_status("has taken a fork", philo);
        pthread_mutex_lock(philo->lf);
        ft_printf_status("has taken a fork", philo);
    }
}

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->parms->death);
    philo->last_meal_time = gettimes();
    philo->meals_count++;
    if (philo->meals_count == philo->parms->max_philo_eat)
        philo->is_full = true;
    pthread_mutex_unlock(philo->parms->death);
    ft_printf_status("is eating", philo);
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
