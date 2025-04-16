/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:49:37 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/16 16:25:40 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void handle1(t_params *par)
{
    printf("0 1 has taken a fork\n");
    ft_usleep(par->time_to_die);
    printf("%d 1 died\n", (par->time_to_die));
    return;
}


void *routine(void *argv)
{
    t_philo *philo;

    philo = (t_philo *)argv;
    // if (philo->id_philo % 2 != 0)
    //     usleep(philo->parms->time_to_eat);
    while (1)
    {
        pthread_mutex_lock(philo->parms->death);
        if (philo->parms->it_over)
        {
            pthread_mutex_unlock(philo->parms->death);
            break;
        }
        pthread_mutex_unlock(philo->parms->death);
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
    pthread_join(monitor_id, NULL);
    return (0);
}
