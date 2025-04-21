/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routing_monitor_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-21 15:11:58 by yhajji            #+#    #+#             */
/*   Updated: 2025-04-21 15:11:58 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void *ft_routing_moniter(t_params *parms)
{
    int i;
    long time;
    int full_philo;


    while (!parms->it_over)
    {
        full_philo = 0;
        i = 0;
        while (i < parms->philo_nbr)
        {
            time = gettime();
            sem_wait(parms->death);
            if (time - parms->philo[i].last_meal_time > parms->time_to_die)
            {
                parms->it_over = 1;
                sem_wait(parms->write);
                printf("%ld %d died\n", time - parms->start, (parms->philo[i].id_philo + 1));
                sem_post(parms->write);
                sem_post(parms->death);
                return (NULL);
            }
            if (parms->philo[i].is_full)
                full_philo++;
            sem_post(parms->death);
            i++;
        }
        if (full_philo == parms->philo_nbr)
        {
            sem_wait(parms->death);
            parms->it_over = 1;
            sem_post(parms->death);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
