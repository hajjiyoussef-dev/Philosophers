/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing_observer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:41:41 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/15 19:54:19 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routing_monitor(void *argv)
{
    t_params *par;
    // t_connect *conn;
    long time_now;
    int full_philo;
    int i;

    par = (t_params *)argv;
    while (!par->it_over)
    {
        // fprintf(stderr, "hana3\n");
        full_philo = 0;
        i = 0;
        while (i < par->philo_nbr)
        {
            time_now = gettimes();
            pthread_mutex_lock(par->death);
            if (time_now - par->philo[i].last_meal_time > par->time_to_die)
            {
                par->it_over = 1;
                printf("%ld %d died\n", time_now - par->start,( par->philo[i].id_philo + 1));
                fflush(stdout);
                pthread_mutex_unlock(par->death);
                return (NULL);
            }
            if (par->check_meal && par->philo[i].meals_count >= par->max_philo_eat)
                full_philo++;
            pthread_mutex_unlock(par->death);
            i++;
        }
        if (par->check_meal && full_philo == par->philo_nbr)
        {
            fprintf(stderr, "hana3\n");
            pthread_mutex_lock(par->death);
            par->it_over = 1;
            pthread_mutex_unlock(par->death);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
    
}
