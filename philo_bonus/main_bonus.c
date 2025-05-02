/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:54:54 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/29 17:54:27 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sem(t_params *par)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/meal_check");
	sem_unlink("/death");
	par->fork = sem_open("/forks", O_CREAT | O_EXCL, 0644, par->philo_nbr);
	if (par->fork == SEM_FAILED)
		return (1);
	par->meal_check = sem_open("/meal_check", O_CREAT | O_EXCL, 0644, 0);
	if (par->meal_check == SEM_FAILED)
		return (1);
	par->write = sem_open("/write", O_CREAT | O_EXCL, 0644, 1);
	if (par->write == SEM_FAILED)
		return (1);
	par->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 1);
	if (par->death == SEM_FAILED)
		return (1);
	return (0);
}

int	init_all(t_params *par, char **argv)
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
	if (par->philo_nbr <= 0 || par->time_to_die <= 0 || par->time_to_eat <= 0
		|| par->time_to_sleep <= 0)
		return (1);
	par->start = 0;
	par->death = 0;
	par->it_over = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	par;

	if ((argc != 5 && argc != 6) || init_all(&par, argv))
		ft_error("invalid arguments", &par, 0);
	if (par.philo_nbr == 1)
		return (handle1(&par), 0);
	if (init_sem(&par))
		ft_error("failed sem init", &par, 1);
	if (philosophers(&par))
		return (ft_clear(&par), EXIT_FAILURE);
	return (0);
}
