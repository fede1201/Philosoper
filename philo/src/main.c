/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:24:07 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/25 17:38:08 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitoring_philo(void *prm)
{
	int		i;
	int		test;
	t_first	*param;

	i = 0;
	param = (t_first *) prm;
	while (1)
	{
		if (param->max_meals == -1)
			test = check_death(param, i);
		else
			test = check_death(param, i) + check_meal(param);
		if (test > 0)
		{
			pthread_mutex_lock(&param->simulation_mutex);
			param->simulation_end = true;
			pthread_mutex_unlock(&param->simulation_mutex);
			break ;
		}
		i = (i + 1) % param->number_of_philo;
	}
	usleep(500);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_first	parameters;

	if (!chk_parameter(ac, av))
		return (1);
	set_struct(ac, av, &parameters);
	begin_philosophers_routine(&parameters);
	destroy_mutex(&parameters);
	return (0);
}
