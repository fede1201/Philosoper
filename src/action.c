/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:21:24 by federico2         #+#    #+#             */
/*   Updated: 2024/11/25 15:07:02 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *philo)
{
	print_msg("is thinking", philo);
	usleep(philo->first->time_to_sleep * 1000);
}

void	sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo);
	usleep(philo->first->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->eating);
	philo->last_meal_time = get_current_time();
	philo->number_of_meals++;
	usleep(philo->first->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
