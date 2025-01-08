/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:17:00 by tom               #+#    #+#             */
/*   Updated: 2024/12/29 16:26:36 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_usage(void)
{
	printf("Usage : ./philosophers %s %s %s %s %s\n",
	"number_of_philosophers",
	"time_to_die",
	"time_to_eat",
	"time_to_sleep",
	"[number_of_times_each_philosopher_must_eat]");
}

void	ft_error(char *error, t_error error_code)
{
	if (error_code == e_too_few_arguments)
		printf("Error : Not enough arguments\n");
	else if (error_code == e_too_many_arguments)
		printf("Error : Too many arguments\n");
	else if (error_code == e_arg_contain_char)
		printf("Error : An argument contain a character\n");
	else if (error != NULL)
		printf("Error : %s\n", error);
	print_usage();
	exit(0);
}
