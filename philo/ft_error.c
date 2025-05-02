/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:40:04 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/27 15:34:46 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear(t_params *par)
{
	int	i;

	if (par->fork != NULL)
	{
		i = 0;
		while (i < par->philo_nbr)
		{
			pthread_mutex_destroy(&par->fork[i]);
			i++;
		}
		free(par->fork);
	}
	if (par->death != NULL)
	{
		pthread_mutex_destroy(par->death);
		free(par->death);
	}
}

void	ft_error(char *str, t_params *par, int flag)
{
	if (flag == 1)
	{
		ft_clear(par);
	}
	printf("Error:{ %s }\n", str);
}
