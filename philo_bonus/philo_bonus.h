/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:55:20 by yhajji            #+#    #+#             */
/*   Updated: 2025/05/15 00:47:06 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_params	t_params;

typedef struct s_params
{
	int					philo_nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_philo_eat;
	int					check_meal;
	long				start;
	int					it_over;

	sem_t				*fork;
	sem_t				*death;
	sem_t				*meal_check;
	sem_t				*write;
	sem_t				*start_simul;
	t_philo				*philo;

}						t_params;

typedef struct s_philo
{
	int					id_philo;
	long				meals_count;
	long				last_meal_time;
	pid_t				process_id;

	t_params			*parms;
}						t_philo;

void					ft_error(char *str, t_params *par, int flag);
int						ft_atoi(const char *str);
void					handle1(t_params *par);
int						philosophers(t_params *par);
long					gettime(void);

void					ft_print_status(char *str, t_philo *philo);
void					ft_usleep(int time_to_sleep);
void					ft_think(t_philo *philo);
void					ft_take_forks(t_philo *philo);
void					ft_eat(t_philo *philo);
void					ft_put_down_forks(t_philo *philo);
void					ft_sleep(t_philo *philo);

void					*ft_routing_moniter(void *argv);
void					ft_kill_process(t_params *par);
void					ft_clear(t_params *par);

void					help_philo(t_params *par);

#endif