/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:55:20 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/20 21:16:38 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS
#define PHILO_BONUS


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/time.h>
//
#include <limits.h>
//
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
    
    

    sem_t   *fork;
    sem_t   *death;
    sem_t   *meal_check;
    sem_t   *write;  
    t_philo *philo;
    
} t_params;

typedef struct s_philo
{
    int     id_philo;
    long    meals_count;
    long    last_meal_time;
    pid_t   process_id;
    bool is_full;

    sem_t   *lf;
    sem_t   *rf;

    t_params *parms;
    
}  t_philo ;


void ft_error(char *str, t_params *par, int flag);
int philosophers(t_params *par);
long gettime();

void ft_think(t_philo *philo);
void ft_take_forks(t_philo *philo);
void ft_eat(t_philo *philo);
void ft_put_down_forks(t_philo *philo);
void ft_sleep(t_philo *philo);

#endif