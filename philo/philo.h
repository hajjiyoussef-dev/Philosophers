/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:52:27 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/10 18:56:02 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>


typedef pthread_mutex_t t_mtx;


typedef struct s_params
{
    int     philo_nbr;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     it_over;
    int     max_philo_eat;
    int     check_meal;
    long    start;
    

    t_mtx *fork;
    
} t_params;

typedef struct s_philo
{
    int     id_philo;
    long    meals_count;
    long    last_meal_time;
    pthread_t   thread_id;

    t_mtx   *lf;
    t_mtx   *rf;

    t_params *parms;
    
}  t_philo ;



int	ft_atoi(const char *str);
void *ft_error(char *str);



#endif