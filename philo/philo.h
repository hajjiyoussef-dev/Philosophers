/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:52:27 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/12 22:34:52 by yhajji           ###   ########.fr       */
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
    int     max_philo_eat;
    int     check_meal;
    long    start;
    int     it_over;
    

    t_mtx   *mutex_over;
    t_mtx   *fork;
    t_mtx   *death;
    
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
void ft_error(char *str);

long gettimes();
int philosophers(t_params *par);
void ft_printf_status(char *msg, t_philo *philo);
void ft_usleep(int time_to_sleep);

void ft_think(t_philo *philo);
void ft_take_forks(t_philo *philo);
void ft_eat(t_philo *philo);
void ft_put_down_forks(t_philo *philo);
void ft_sleep(t_philo *philo);




#endif