/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:51:04 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/21 15:36:00 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void print_msg(char *str, t_philo *philo)
{
	size_t time;
	pthread_mutex_lock(&philo->first->print);
	time = get_current_time() - philo->first->starting_time;
	if(!chk_philosopher_dead(philo->first))
		printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->first->print);
}
size_t   get_current_time()
{
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
static  void destroy_philo_mutex(t_first *param)
{
	int i;

	i = 0;
	while(i < param->number_of_philo)
	{
		pthread_mutex_destroy(&param->philo[i].eating);
		i++;
	}
	free(param->philo);
}
static  void destroy_fork(t_first *param)
{
	int i;

	i = 0;
	while(i < param->number_of_philo)
	{
		pthread_mutex_destroy(&param->fork[i]);
		i++;
	}
	free(param->fork);
}
void	destroy_mutex(t_first *param)
{
	pthread_mutex_destroy(&param->simulation_mutex);
	pthread_mutex_destroy(&param->lock_number_of_meals);
	pthread_mutex_destroy(&param->print);
	pthread_mutex_destroy(&param->death_lock);
	pthread_mutex_destroy(&param->ready_lock);
	destroy_fork(param),
	destroy_philo_mutex(param);
	
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
