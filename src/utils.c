/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:56:23 by tom               #+#    #+#             */
/*   Updated: 2024/12/29 17:20:03 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int print_data(t_philo *philo, t_action act, int time)
{
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	if (act == e_take_fork)
		write(1, TAKE_FORK_PROMPT, TAKE_FORK_PROMPT_SIZE);
	else if (act == e_eat)
		write(1, EAT_PROMPT, EAT_PROMPT_SIZE);
	else if (act == e_sleep)
		write(1, SLEEP_PROMPT, SLEEP_PROMPT_SIZE);
	else if (act == e_think)
		write(1, THINK_PROMPT, THINK_PROMPT_SIZE);
	else if (act == e_die)
		write(1, DIE_PROMPT, DIE_PROMPT_SIZE);
	return (1);
}

int	ft_strcmp(char *first, char *second)
{
	int	i;

	i = -1;
	while (first[++i] && second[i])
		if (first[i] != second[i])
			return (((unsigned char)first[i]) - ((unsigned char)second[i]));
	return (((unsigned char)first[i]) - ((unsigned char)second[i]));
}

int	ft_atoi(const char	*str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

bool	ft_all_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}
