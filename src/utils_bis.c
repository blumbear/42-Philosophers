/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:15:41 by tom               #+#    #+#             */
/*   Updated: 2024/12/30 18:15:53 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	unsigned char	*bmem;
	size_t			i;

	i = 0;
	bmem = malloc((nmemb) * size);
	if (!bmem)
		return (NULL);
	while (i < (nmemb) * size)
	{
		bmem[i] = 0;
		i++;
	}
	return ((void *) bmem);
}
