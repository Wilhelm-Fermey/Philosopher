/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:30:41 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/09 13:28:18 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "philo.h"

typedef struct s_philo
{
	int				philo_id;
	int				total_nbr_of_meals;
	int				total_nbr_of_meals_1;
	time_t			life;
	int				nbr_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	time_t			limit_of_life;
	int				stop;
	time_t			start;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	int				nbr_philo;
	int				philo_id;
	time_t			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				nbr_of_meals;
	pthread_mutex_t	*mutex;
	pthread_t		*tids;
	pthread_mutex_t	lock_print;
	t_philo			*all_philos;
}					t_rules;

/* ****************************** MAIN ********************************** */
void	*ft_process(void *args);

/* ******************************* INIT ********************************** */
void	ft_init_philosophers(t_rules *rules);
void	ft_init_mutex(t_rules *rules);
void	ft_init_threads(t_rules *rules);
int		ft_init_rules(t_rules *rules, int argc, char **argv);

/* **************************** DESTROY ********************************* */
void	free_all(t_rules *rules);
void	unlock_and_destroy_mutex(t_rules *rules);
void	ft_end_threads(t_rules *rules);

/* **************************** ACTION ********************************** */
void	taking_forks_else(t_philo *philo);
void	taking_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/* ***************************** DEATH *********************************** */
void	*death_loop(void *args);
void	died_philo(t_philo *philo, int i);

/* ****************************** TIME *********************************** */
long	ft_time(void);
void	ft_usleep(int ms);

/* ***************************** UTILS *********************************** */
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);

/* ***************************** CHECK *********************************** */
int		ft_check(int argc, char **argv);
int		ft_wait(char **argv);

#endif
