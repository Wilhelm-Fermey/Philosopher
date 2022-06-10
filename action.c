/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:38:24 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/09 12:18:39 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks_else(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(philo->r_f);
	pthread_mutex_lock(&philo->lock_print);
	if (philo->stop != 1)
	{
		printf("%ld %d has taken a fork\n", \
			ft_time() - philo->start, philo->philo_id + 1);
		printf("%ld %d has taken a fork\n", \
			ft_time() - philo->start, philo->philo_id + 1);
	}
	pthread_mutex_unlock(&philo->lock_print);
}

void	taking_forks(t_philo *philo)
{
	if ((philo->philo_id) % 2 == 0 && philo->philo_id + 1 != philo->nbr_philo)
	{
		pthread_mutex_lock(philo->r_f);
		pthread_mutex_lock(philo->l_f);
		pthread_mutex_lock(&philo->lock_print);
		if (philo->stop != 1)
		{
			printf("%ld %d has taken a fork\n", \
				ft_time() - philo->start, philo->philo_id + 1);
			printf("%ld %d has taken a fork\n", \
				ft_time() - philo->start, philo->philo_id + 1);
		}
		pthread_mutex_unlock(&philo->lock_print);
	}
	else
		taking_forks_else(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld %d is eating\n", \
		ft_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	philo->total_nbr_of_meals += 1;
	philo->life = ft_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld %d is sleeping\n", \
		ft_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld %d is thinking\n", \
		ft_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
}
