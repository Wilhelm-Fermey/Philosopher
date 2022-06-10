/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:57:52 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/09 13:22:25 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_zero(int argc, char **argv)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		if (! ft_strcmp(argv[i], "0"))
			return (1);
		if (j > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				count++;
			j++;
		}
		i++;
	}
	if (count || ft_check_zero(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

int	ft_wait(char **argv)
{
	int		i;
	time_t	start;

	i = ft_atoi(argv[2]);
	start = ft_time();
	ft_usleep(i);
	printf("%ld %d died\n", ft_time() - start, 1);
	return (0);
}
