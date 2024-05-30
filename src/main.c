/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:16 by tom               #+#    #+#             */
/*   Updated: 2024/05/30 14:19:49 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *error)
{
	if (ft_strcmp("UsageS", error) == 0)
		printf("Error : Not enough arguments\nUsage : %s %s %s %s %s %s\n",
		"./philosophers", "number_of_philosophers",
		"time_to_die", "time_to_eat", "time_to_sleep",
		"[number_of_times_each_philosopher_must_eat]");
	else if (ft_strcmp("UsageH", error) == 0)
		printf("Error : Too many arguments\nUsage : %s %s %s %s %s %s\n",
		"./philosophers", "number_of_philosophers",
		"time_to_die", "time_to_eat", "time_to_sleep",
		"[number_of_times_each_philosopher_must_eat]");
	else
		printf("Error : %s\n", error);
	exit(0);
}

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 5)
		ft_error("UsageS");
	if (ac > 6)
		ft_error("UsageH");
	av++;
	while (av[++i])
		if (!ft_all_isdigit(av[i]))
			ft_error("The value cant contain any char");
	
}
