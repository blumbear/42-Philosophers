/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:56:23 by tom               #+#    #+#             */
/*   Updated: 2024/05/30 14:12:40 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(char *first, char *second)
{
	int	i;

	i = -1;
	while (first[++i] && second[i])
		if (first[i] != second[i])
			return (((unsigned char)first[i]) - ((unsigned char)second[i]));
	return (((unsigned char)first[i]) - ((unsigned char)second[i]));
}

bool	ft_all_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 0 && !str[i + 1])
			return (true);
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}
