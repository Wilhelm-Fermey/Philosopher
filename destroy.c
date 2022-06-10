/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:35:45 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/09 12:32:01 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_rules *rules)
{
	free(rules->tids);
	free(rules->all_philos);
	free(rules->mutex);
}

void	unlock_and_destroy_mutex(t_rules *rules)
{
	int	i;

	i = rules->nbr_philo;
	while (i--)
	{
		pthread_mutex_unlock(&rules->mutex[i]);
		pthread_mutex_destroy(&rules->mutex[i]);
	}
	pthread_mutex_unlock(&(*rules).lock_print);
	pthread_mutex_destroy(&(*rules).lock_print);
}

void	ft_end_threads(t_rules *rules)
{
	int	i;

	i = rules->nbr_philo;
	if (i == 1)
		pthread_mutex_unlock(&rules->mutex[0]);
	while (i)
	{
		i--;
		pthread_join(rules->tids[i], NULL);
	}
}
