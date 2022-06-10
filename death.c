/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:40:39 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/10 11:49:11 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_loop(void *args)
{
	t_philo	*philo;
	long	time_now;
	int		i;

	philo = (t_philo *)args;
	i = 0;
	while (philo[i].stop == 0)
	{
		i = -1;
		while (++i < philo->nbr_philo)
		{
			time_now = ft_time();
			if (philo[i].stop != 0)
				return (NULL);
			if (time_now - philo[i].life > philo[i].limit_of_life)
			{
				died_philo(philo, i);
				pthread_mutex_unlock(&philo->lock_print);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	died_philo(t_philo *philo, int i)
{
	philo->rules->dead = 1;
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld %d died\n", ft_time() - philo->start,
		philo[i].philo_id + 1);
	i = -1;
	while (i < philo[i].nbr_philo)
	{
		philo[i].stop = 1;
		i++;
	}
}
