/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:20:03 by yhajji            #+#    #+#             */
/*   Updated: 2025/04/11 15:24:08 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	help_atoi(long long arr[], const char *str, int *error)
{
	if (!ft_isdigit(str[arr[2]]))
	{
		*error = 1;
		return (0);
	}
	if ((arr[0] > (2147483647 / 10) || (arr[0] == 2147483647 / 10 && (str[arr[2]] - '0') > 7)) || (arr[1] == -1 && arr[0] == 2147483647 / 10 && (str[arr[2]] - '0') == 8))
	{
		*error = 1;
		return (0);
	}
	arr[0] = (str[arr[2]] - 48) + (arr[0] * 10);
	return (arr[0]);
}

int	ft_atoi(const char *str)
{
	long long	arr[3];
	int			error;

	error = 0;
	arr[0] = 0; // res
	arr[1] = 1; // sig
	arr[2] = 0; // i
	while (str[arr[2]] == ' ' || str[arr[2]] == '\f' || str[arr[2]] == '\n'
		|| str[arr[2]] == '\r' || str[arr[2]] == '\v')
		arr[2]++;
	if (str[arr[2]] == '-' && ft_isdigit(str[arr[2] + 1]))
		arr[1] *= -1;
	if ((str[arr[2]] == '+' && ft_isdigit(str[arr[2] + 1]))
		|| (str[arr[2]] == '-' && ft_isdigit(str[arr[2] + 1])))
		arr[2]++;
	while (str[arr[2]])
	{
		arr[0] = help_atoi(arr, str, &error);
		if (error == 1)
			return (0);
		arr[2]++;
	}	
	return (arr[0] * arr[1]);
}
