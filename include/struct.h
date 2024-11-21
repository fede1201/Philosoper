/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico2 <federico2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:13:26 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/05 19:12:35 by federico2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "struct.h"
# include <stdlib.h>      // memset, malloc, free
# include <stdio.h>       // printf
# include <unistd.h>      // write, usleep
# include <sys/time.h>    // gettimeofday
# include <pthread.h>     // pthread_create
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>   

typedef struct s_first t_first;

typedef struct s_philo
{
	int						id;
	int						number_of_meals;
	int						*is_dead;
	size_t					last_meal_time;
	pthread_t 				thread_id;
	pthread_mutex_t 		eating;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
	t_first					*first;
}	t_philo;

typedef struct s_first
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					philosopher_dead;
	int					max_meals;
	size_t				starting_time;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		lock_number_of_meals;
	pthread_mutex_t 	print;
	pthread_mutex_t 	death_lock;
	pthread_mutex_t		ready_lock;
}	t_first;

#endif