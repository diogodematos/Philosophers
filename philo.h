/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:32:21 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/03 13:04:06 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_t	*p;
}								t_philo;

t_philo	*philo(void);
int ft_check_args(int argc, char **argv);
int	init_philo(char **argv);
void*	see(void);


#endif
