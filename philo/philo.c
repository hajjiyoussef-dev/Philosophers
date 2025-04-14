/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:49:37 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/14 22:43:48 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// int it_not_over_yeat(t_philo *philo)
// {
//     long time;
//     long death_time;
    
//     time = gettimes();
//     if (time - philo->last_meal_time > philo->parms->time_to_die)
//     {
//         pthread_mutex_lock(philo->parms->death);
//         if (!philo->parms->it_over)
//         {
//             philo->parms->it_over = 1;
//             death_time = gettimes() - philo->parms->start;
//             printf("%ld %d died\n", death_time, philo->id_philo + 1);
//             fflush(stdout);
//         }
//         pthread_mutex_unlock(philo->parms->death);
//         return (0);
//     }
//     if (philo->parms->check_meal && philo->meals_count >= philo->parms->max_philo_eat)
//     {
//         return (0);
//     }
//     return (1);
// }

void *routine(void *argv)
{
    t_philo *philo;

    philo = (t_philo *)argv;
    if (philo->id_philo % 2 != 0)
        usleep(1000);
    while (!(philo->parms->it_over))
    {
        ft_take_forks(philo);
        ft_eat(philo);
        ft_put_down_forks(philo);
        ft_sleep(philo);
        ft_think(philo);
    }
    return (NULL);
}

long gettimes()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

int init_philosophers(t_params *par, t_philo *philo)
{
    int i;

    i = 0;
    // fprintf(stderr, "hana1\n");
    while (i < par->philo_nbr)
    {
       philo[i].id_philo = i;
       philo[i].last_meal_time = par->start;
       philo[i].meals_count = 0;
       philo[i].parms = par;
       philo[i].lf = &par->fork[i];
       philo[i].rf = &par->fork[((i + 1) % par->philo_nbr)];
       par->philo = philo;
       i++;
    }
    return (0);
}

int philosophers(t_params *par)
{
    t_philo *philo;
    int i;
    pthread_t monitor_id;

    philo = malloc(sizeof(t_philo) * par->philo_nbr);
    if (!philo)
        return (1);
    par->start = gettimes();
    init_philosophers(par, philo);
    pthread_create(&monitor_id, NULL, routing_monitor, par);
    i = 0;
    while (i < par->philo_nbr)
    {
        if (pthread_create(&philo[i].thread_id, NULL, routine, &philo[i]) != 0)
            return (1);
        usleep(100);
        i++;
    }
    i = 0;
    while (i < par->philo_nbr)
    {
        pthread_join(philo[i].thread_id, NULL);
        i++;
    }
    return (0);
}
