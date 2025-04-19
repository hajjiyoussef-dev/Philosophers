/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:54:54 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/19 19:37:02 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int init_sem(t_params *par)
{
	
}

int init_all(t_params *par, char **argv)
{
	par->philo_nbr = ft_atoi(argv[1]);
    par->time_to_die = ft_atoi(argv[2]);
    par->time_to_eat = ft_atoi(argv[3]);
    par->time_to_sleep = ft_atoi(argv[4]);
    par->check_meal = 0;
    par->max_philo_eat = -1;

    if (argv[5])
    {
        par->check_meal = 1;
        par->max_philo_eat = ft_atoi(argv[5]);
        if (par->max_philo_eat <= 0)
            return (1);
    }
    if (par->philo_nbr <= 0 || par->time_to_die <= 0 || par->time_to_eat <= 0 || par->time_to_sleep <= 0)
        return (1);
    par->start = 0;
    par->death = 0;
        
    return (0);
}

int main(int argc, char **argv)
{
	t_params par;

	if ((argc != 5 && argc != 6) || init_all(&par, argv))
		ft_error("invalid arguments");
	if(par.philo_nbr == 1)
		return (handle1(&par), 0);
	if(init_sem(&par))
		ft_error("failed sem init");
	if (philosophers(&par))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}