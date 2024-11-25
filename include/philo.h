/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:05 by fluzi             #+#    #+#             */
/*   Updated: 2024/11/25 15:45:45 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>      // memset, malloc, free
# include <stdio.h>       // printf
# include <unistd.h>      // write, usleep
# include <sys/time.h>    // gettimeofday
# include <pthread.h>     // pthread_create
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>      // size_t

typedef struct s_first	t_first;

typedef struct s_philo
{
	int						id;
	int						number_of_meals;
	int						*is_dead;
	size_t					last_meal_time;
	pthread_t				thread_id;
	pthread_mutex_t			eating;
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
	bool				simulation_end;
	size_t				starting_time;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		simulation_mutex;
	pthread_mutex_t		lock_number_of_meals;
	pthread_mutex_t		print;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		ready_lock;
}	t_first;

//chk
bool			ft_atoi_ck(const char *str);
bool			chk_parameter(int ac, char **av);
bool			ft_isdigit(char *str);
//utils
int				ft_atoi(const char *str);
void			set_struct(int ac, char **av, t_first *parameters);
size_t			get_current_time(void);
void			print_msg(char *str, t_philo *philo);
int				u_max_meals(int ac, char **av);
void			destroy_mutex(t_first *param);
void			single_philosopher(t_philo *philo);
// monitoring
int				check_death(t_first *param, int i);
int				check_meal(t_first *param);
int				chk_philosopher_dead(t_first *param);
int				chk_status(t_philo *philo, int stat);
// action
void			eat(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			begin_philosophers_routine(t_first *parameters);
void			*monitoring_philo(void *prm);

#endif