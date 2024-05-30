/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:29 by tom               #+#    #+#             */
/*   Updated: 2024/05/30 14:07:29 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct s_philosophers
{
	int	id;
	
}	t_philosophers;

/******************************************************************************/
/*                                                                            */
/* utils                                                                      */
/*                                                                            */
/******************************************************************************/

int		ft_strcmp(char *first, char *second);
bool	ft_all_isdigit(char *str);
