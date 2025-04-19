/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:05:45 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/13 21:45:51 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_usleep(int time_to_sleep, t_philo *philo)
{
    if (philo->parms->time_to_die < time_to_sleep)
        usleep(philo->parms->time_to_die * 1000);
    else
        usleep(time_to_sleep * 1000);
}

void ft_printf_status(char *msg, t_philo *philo)
{
    long time;

    pthread_mutex_lock(philo->parms->death);
    time =(gettimes() - philo->parms->start);
    if (!philo->parms->it_over)
    {
        printf("%ld %d %s\n", time, (philo->id_philo + 1), msg);
        fflush(stdout);
    }
    pthread_mutex_unlock(philo->parms->death);
}
