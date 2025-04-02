/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:03 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/25 13:44:55 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static bool	chk_numbers(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_atoi_ck(av[i]))
			return (false);
		if (!ft_isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	chk_parameter(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("Error\n./philo[n_philo[t_die][t_eat][t_sleep]"), false);
	if (!chk_numbers(av))
		return (printf("Error\nInvalid parameters"), false);
	return (true);
}
