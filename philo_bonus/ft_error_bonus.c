/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:26:34 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/20 20:37:12 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_clear(t_params *par)
{
    if (par->fork && par->fork != SEM_FAILED)
    {
        sem_close(par->fork);
        sem_unlink("/forks");
    }
    if (par->write && par->write != SEM_FAILED)
    {
        sem_close(par->write);
        sem_unlink("/write");
    }
    if (par->meal_check && par->meal_check != SEM_FAILED)
    {
        sem_close(par->meal_check);
        sem_unlink("/meal_check");
    }
    if (par->death && par->death != SEM_FAILED)
    {
        sem_close(par->death);
        sem_unlink("/death");
    }
}


void ft_error(char *str, t_params *par, int flag)
{
    if (flag == 1)
        ft_clear(par);
    printf("Error:{ %s }\n", str);
    exit(1);
}
