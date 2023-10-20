/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:13:52 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/20 16:51:12 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	redmutex(int i, int p)
{
	if (i == 1)
	{
		pthread_mutex_lock(&philo()[p].lock);
		pthread_mutex_lock(&stru()->lock);
	}
	else
	{
		pthread_mutex_unlock(&stru()->lock);
		pthread_mutex_unlock(&philo()[p].lock);
	}
}
