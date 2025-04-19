/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:55:20 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/19 16:14:44 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS
#define PHILO_BONUS


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include <limits.h>
#include <stdbool.h>




typedef struct s_philo t_philo;
typedef struct s_params  t_params;



typedef struct s_params
{
    int     philo_nbr;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     max_philo_eat;
    int     check_meal;
    long    start;
    int     it_over;
    

    sem_t   *mutex_over;
    sem_t   *fork;
    sem_t   *death;
    t_philo *philo;
    
} t_params;

typedef struct s_philo
{
    int     id_philo;
    long    meals_count;
    long    last_meal_time;
    pid_t   thread_id;
    bool is_full;

    sem_t   *lf;
    sem_t   *rf;

    t_params *parms;
    
}  t_philo ;

#endif