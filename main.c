/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:29:16 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/10 12:51:51 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_start(t_philo *philo)
{
	philo->life = ft_time();
	philo->start = ft_time();
}	

void	*ft_process(void *args)
{
	t_philo		*philo;
	int			i;

	i = -1;
	philo = (t_philo *)args;
	init_start(philo);
	while (!philo->rules->dead && ++i != philo->total_nbr_of_meals_1)
	{
		if (philo->rules->dead || philo->stop)
			return (NULL);
		taking_forks(philo);
		if (philo->rules->dead || philo->stop)
			return (NULL);
		eating(philo);
		if (philo->rules->dead || philo->stop)
			return (NULL);
		sleeping(philo);
		if (philo->rules->dead || philo->stop)
			return (NULL);
		thinking(philo);
		if (philo->rules->dead || philo->stop)
			return (NULL);
	}
	philo->stop = 1;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc == 5 || argc == 6)
	{	
		if (ft_check(argc, argv))
			return (1);
		if (ft_atoi(argv[1]) == 1)
			return (ft_wait(argv));
		if (ft_init_rules(&rules, argc, argv) == 1)
			return (1);
		ft_init_mutex(&rules);
		ft_init_philosophers(&rules);
		ft_init_threads(&rules);
		ft_end_threads(&rules);
		unlock_and_destroy_mutex(&rules);
		free_all(&rules);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (0);
	}
}
