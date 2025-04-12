/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:49:37 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/11 23:14:18 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routine()
{
    
}

long gettimes()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

int init_philosophers(t_params *par, t_philo *philo)
{
    int i;

    i = 0;

    while (i < par->philo_nbr)
    {
       philo[i].id_philo = i;
       philo[i].last_meal_time = 0;
       philo[i].meals_count = 0;
       philo[i].parms = par;
       philo[i].lf = &par->fork[i];
       philo[i].rf = &par->fork[((philo->id_philo + 1) % par->philo_nbr)];
       i++;
    }
    return (0);
}

int philosophers(t_params *par)
{
    t_philo *philo;
    int i;

    philo = malloc(sizeof(t_philo) * par->philo_nbr);
    if (!philo)
        return (1);
    init_philosophers(par, philo);
    i = 0;
    par->start = gettimes();
    while (i < par->philo_nbr)
    {
        if (pthread_create(&philo[i].thread_id, NULL, routine, &philo[i]) != 0)
            return (1);
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