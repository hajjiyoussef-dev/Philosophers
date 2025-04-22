/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:26:00 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/21 20:38:50 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void kill_all_processes(t_params *par)
{
	int i;

	i = 0;
	while (i < par->philo_nbr)
	{
		kill(par->philo[i].process_id, SIGKILL);
		i++;
	}	
}


void ft_kill_process(t_params *par)
{
	int i;
	int status;
	int is_full;

	i = 0;
	is_full = 0;
	while (i < par->philo_nbr)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				kill_all_processes(par);
				break;
			}
			else if (WEXITSTATUS(status) == 0)
			{
				is_full++;
				if (is_full == par->philo_nbr)
					break;
			}
		}
		i++;
	}
}
