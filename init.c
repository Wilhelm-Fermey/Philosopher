/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:33:45 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/09 12:51:31 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philosophers(t_rules *rules)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * rules->nbr_philo);
	while (i < rules->nbr_philo)
	{
		philos[i].philo_id = i;
		philos[i].nbr_philo = rules->nbr_philo;
		philos[i].total_nbr_of_meals = 0;
		philos[i].total_nbr_of_meals_1 = rules->nbr_of_meals;
		philos[i].time_to_eat = rules->time_to_eat;
		philos[i].time_to_sleep = rules->time_to_sleep;
		philos[i].time_to_die = rules->time_to_die;
		philos[i].life = ft_time();
		philos[i].limit_of_life = rules->time_to_die;
		philos[i].stop = 0;
		philos[i].l_f = \
			&rules->mutex[philos[i].philo_id];
		philos[i].r_f = \
			&rules->mutex[(philos[i].philo_id + 1) % rules->nbr_philo];
		philos[i].rules = rules;
		i++;
	}
	rules->all_philos = philos;
}

void	ft_init_mutex(t_rules *rules)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = rules->nbr_philo;
	mutex = malloc(sizeof(pthread_mutex_t) * i);
	while (i--)
		pthread_mutex_init(&mutex[i], NULL);
	pthread_mutex_init(&rules->lock_print, NULL);
	rules->mutex = mutex;
}

void	ft_init_threads(t_rules *rules)
{
	int			i;
	pthread_t	*threads;
	pthread_t	s_tid;

	i = rules->nbr_philo;
	threads = malloc(sizeof(pthread_t) * i);
	while (i--)
		pthread_create(&threads[i], \
			NULL, ft_process, (void *)&rules->all_philos[i]);
	pthread_create(&s_tid, NULL, death_loop, (void *)rules->all_philos);
	pthread_join(s_tid, NULL);
	rules->tids = threads;
}

int	ft_init_rules(t_rules *rules, int argc, char **argv)
{
	rules->nbr_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->dead = 0;
	if (argc == 6)
		rules->nbr_of_meals = ft_atoi(argv[5]);
	if (argc == 5)
	{
		if (rules->nbr_philo < 1)
			return (0);
		rules->nbr_of_meals = -1;
	}
	if (argc == 6)
	{
		if (rules->nbr_of_meals < 1)
			return (0);
	}
	return (0);
}
