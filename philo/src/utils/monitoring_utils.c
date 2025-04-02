/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:04 by federico2         #+#    #+#             */
/*   Updated: 2024/11/25 13:48:17 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	chk_status(t_philo *philo, int stat)
{
	int	ret;

	ret = 0;
	if (stat == 0)
	{
		if (chk_philosopher_dead(philo->first) == 1)
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			ret = 1;
		}
	}
	else if (stat > 0)
	{
		if (chk_philosopher_dead(philo->first) == 1)
			ret = 1;
	}
	return (ret);
}

int	chk_philosopher_dead(t_first *param)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&param->death_lock);
	pthread_mutex_lock(&param->simulation_mutex);
	if (param->philosopher_dead == 1 || param->simulation_end == true)
		ret = 1;
	pthread_mutex_unlock(&param->simulation_mutex);
	pthread_mutex_unlock(&param->death_lock);
	return (ret);
}

int	check_meal(t_first *param)
{
	int	i;

	i = 0;
	while (i < param->number_of_philo)
	{
		pthread_mutex_lock(&param->philo[i].eating);
		if (param->philo[i].number_of_meals < param->max_meals)
		{
			pthread_mutex_unlock(&param->philo[i].eating);
			return (0);
		}
		pthread_mutex_unlock(&param->philo[i].eating);
		i++;
	}
	print_msg("All philosophers are full", &param->philo[0]);
	pthread_mutex_lock(&param->simulation_mutex);
	param->simulation_end = true;
	pthread_mutex_unlock(&param->simulation_mutex);
	return (1);
}

int	check_death(t_first *param, int i)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&param->philo[i].eating);
	if (get_current_time() - param->philo[i].last_meal_time
		>= (size_t) param->time_to_die)
	{
		print_msg("died", &param->philo[i]);
		pthread_mutex_lock(&param->death_lock);
		param->philosopher_dead = 1;
		ret = 1;
		pthread_mutex_unlock(&param->death_lock);
	}
	pthread_mutex_unlock(&param->philo[i].eating);
	return (ret);
}
