/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:16 by tom               #+#    #+#             */
/*   Updated: 2024/12/30 19:08:51 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_env *env)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&env->print);
	while (++i < env->n_philo)
	{
		pthread_mutex_destroy(&env->philo[i].dead);
		pthread_mutex_destroy(&env->philo[i].eat);
		pthread_mutex_destroy(&env->philo[i].fork);
	}
	free(env->philo);
}

t_philo	init_philo(int i, t_env *env)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.eating = false;
	philo.sleeping = false;
	philo.thinking = false;
	philo.alive = true;
	philo.left_fork = false;
	philo.right_fork = false;
	philo.last_eat = get_time();
	philo.last_sleep = 0;
	philo.nb_meal = 0;
	philo.env = env;
	return (philo);
}

void	create_philo(t_env *env)
{
	int	i;

	i = -1;
	env->philo = ft_calloc(env->n_philo + 1, sizeof(t_philo));
	while (++i < env->n_philo)
	{
		env->philo[i] = init_philo(i, env);
		pthread_mutex_init(&env->philo[i].dead, NULL);
		pthread_mutex_init(&env->philo[i].eat, NULL);
		pthread_mutex_init(&env->philo[i].fork, NULL);
		printf("i = %d index = %d\n", i, env->philo[i].id);
	}
}

void	run_philo(t_env *env)
{
	int i;

	i = 0;
	while (!env->death)
	{
		i++;
		if (i > env->n_philo)
			i = 0;
	}
}

int	main(int ac, char **av)
{
	t_env env;

	av++;
	if (!check_arg(ac, av, &env))
		return (EXIT_SUCCESS);
	create_philo(&env);
	//run_philo(&env);
	free_all(&env);
}
