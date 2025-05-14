/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:52:17 by yhajji            #+#    #+#             */
/*   Updated: 2025/05/13 19:08:00 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mtx(t_params *par)
{
	int	i;

	par->fork = malloc(sizeof(pthread_mutex_t) * par->philo_nbr);
	if (!par->fork)
		return (1);
	par->death = malloc(sizeof(pthread_mutex_t));
	if (!par->death)
		return (1);
	if (pthread_mutex_init(par->death, NULL) != 0)
		return (1);
	par->it_over = 0;
	par->philo = NULL;
	i = 0;
	while (i < par->philo_nbr)
	{
		if (pthread_mutex_init(&par->fork[i], NULL) != 0)
			return (1);
		i++;
	}
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
	return (0);
}

int	main(int argc, char *argv[])
{
	t_params	p;

	if ((argc != 5 && argc != 6) || init_all(&p, argv))
	{
		ft_error("invalid arguments", &p, 0);
		return (EXIT_FAILURE);
	}
	if (init_mtx(&p))
	{
		ft_error("failed mutex init", &p, 1);
		return (EXIT_FAILURE);
	}
	if (p.philo_nbr == 1)
		return (handle1(&p), ft_clear(&p), 0);
	if (philosophers(&p))
		return (ft_clear(&p), EXIT_FAILURE);
	return (ft_clear(&p), EXIT_SUCCESS);
}
