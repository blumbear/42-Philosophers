/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:32:03 by tom               #+#    #+#             */
/*   Updated: 2024/12/30 18:54:30 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_env_value(t_env *env)
{
	if (env->n_philo < 0)
		return (false);
	if (env->t_die < 0)
		return (false);
	if (env->t_sleep < 0)
		return (false);
	if (env->t_eat < 0)
		return (false);
	return (true);
}

bool	var_init(t_env	*env, char	**av)
{
	int	i;

	i = -1;
	env->m_eat = -1;
	while (av[++i])
	{
		if (!ft_all_isdigit(av[i]))
			return (false);
		if (i == 0)
			env->n_philo = ft_atoi(av[i]);
		else if (i == 1)
			env->t_die = ft_atoi(av[i]);
		else if (i == 2)
			env->t_eat = ft_atoi(av[i]);
		else if (i == 3)
			env->t_sleep = ft_atoi(av[i]);
		else if (i == 4)
			env->m_eat	 = ft_atoi(av[i]);
	}
	if (!check_env_value(env))
		return (false);
	pthread_mutex_init(&env->print, NULL);
	env->death = false;
	return (true);
}

bool	check_arg(int ac, char **av, t_env *env)
{
	if (ac < 5)
		ft_error(NULL, e_too_few_arguments);
	else if (ac > 6)
		ft_error(NULL, e_too_many_arguments);
	else if (!var_init(env, av))
		ft_error(NULL, e_arg_contain_char);
	else
		return (true);
	return (false);
}
