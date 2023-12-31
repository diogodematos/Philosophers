/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philopthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:00:59 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/20 18:41:49 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	all_eat(void)
{
	if (stru()->philo_eat_count == stru()->nb_philo)
	{
		pthread_mutex_unlock(&stru()->lock);
		return (1);
	}
	return (0);
}

void	*control_routine(void *arg)
{
	int				i;
	unsigned long	time;

	(void)arg;
	i = 0;
	while (i <= stru()->nb_philo)
	{
		redmutex(1, i);
		if (all_eat())
			break ;
		redmutex(0, i);
		pthread_mutex_lock(&philo()[i].lock);
		time = philo()[i].t_philo_die;
		if (((get_time() - stru()->start_time) > time) && !philo()[i].is_eat)
		{
			menssage("died", &philo()[i]);
			break ;
		}
		pthread_mutex_unlock(&philo()[i].lock);
		i++;
		if (i == stru()->nb_philo)
			i = 0;
	}
	pthread_mutex_unlock(&philo()[i].lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (stru()->nb_philo == 1)
	{
		menssage("has taken a fork", philo);
		usleep(stru()->t_die * 1000);
		menssage("dead", philo);
		return (NULL);
	}
	while (1)
	{
		if (eat(philo))
			break ;
		if (slepping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

int	init_threads(void)
{
	int	i;

	i = -1;
	stru()->start_time = get_time();
	while (++i < stru()->nb_philo)
	{
		if (pthread_create(&stru()->thread[i], NULL, &routine, &philo()[i]))
			return (printf("ERROR CREATE PTHREAD"));
		usleep(1);
	}
	if (i > 0)
		if (pthread_create(&stru()->control, NULL, &control_routine, NULL))
			return (1);
	i = -1;
	while (++i < stru()->nb_philo)
		pthread_join(stru()->thread[i], NULL);
	if (i > 0)
		pthread_join(stru()->control, NULL);
	return (0);
}
