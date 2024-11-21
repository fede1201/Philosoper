/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:21:33 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/21 15:31:34 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void take_fork(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo);
	}
	else 
	{
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
	}
}
void *philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	while(chk_philosopher_dead(philo->first) == 0)
	{
		pthread_mutex_lock(&philo->first->print);
		pthread_mutex_unlock(&philo->first->print);
		take_fork(philo);
		if(chk_status(philo, 0) == 1)
			break;
		eat(philo);
		if(chk_status(philo, 1) == 1)
			break;
		sleeping(philo);
		if(chk_status(philo, 1) == 1)
			break;
		thinking(philo);
		if(chk_status(philo, 1) == 1)
			break;
	}
	return (NULL);
}
void	begin_philosophers_routine(t_first *parameters)
{
	int	i;
	pthread_t id_monitor;

	i = 0;
	while (i < parameters->number_of_philo)
	{
		pthread_create(&parameters->philo[i].thread_id, NULL, &philo_routine, (void *) &parameters->philo[i]);
		i++;
	}
	pthread_create(&id_monitor, NULL, &monitoring_philo, (void *) parameters);	
	i = 0;
	while (i < parameters->number_of_philo)
	{
		pthread_join(parameters->philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(id_monitor, NULL);
}

