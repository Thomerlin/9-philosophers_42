/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:45:04 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/07/29 00:14:02 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	finish2(t_gen *gen)
{
	int	i;

	i = -1;
	while (++i < gen->philo_count)
		pthread_mutex_destroy(&gen->fork[i].mutex);
	pthread_mutex_destroy(&gen->m_meal);
	pthread_mutex_destroy(&gen->m_write);
	pthread_mutex_destroy(&gen->m_dead);
	pthread_mutex_destroy(&gen->m_fork);
	pthread_mutex_destroy(&gen->m_win);
	pthread_mutex_destroy(&gen->m_to_eat);
	free(gen->philo);
	free(gen->fork);
}

void	finish(t_gen *gen)
{
	int	i;

	i = -1;
	while (++i < gen->philo_count)
		pthread_join(gen->philo[i].thread, NULL);
	finish2(gen);
}
