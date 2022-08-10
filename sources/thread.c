/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:21:26 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/07/29 00:10:19 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eat(t_philo *philo)
{
	while (1)
	{
		if (take_fork(philo, &philo->gen->fork[philo->left]))
			break ;
		usleep(100);
	}
	while (1)
	{
		if (take_fork(philo, &philo->gen->fork[philo->right]))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&philo->gen->m_meal);
	write_status(philo->gen, philo->id, "Is eating!");
	philo->last_meal = get_real_time();
	pthread_mutex_unlock(&philo->gen->m_meal);
	smart_sleep(philo->gen->eat_time, philo->gen);
	pthread_mutex_lock(&philo->gen->m_to_eat);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->gen->m_to_eat);
	release_fork(&philo->gen->fork[philo->left]);
	release_fork(&philo->gen->fork[philo->right]);
}

void	*thread(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (!check_died(philo->gen))
	{
		eat(philo);
		if (check_win(philo->gen))
			break ;
		write_status(philo->gen, philo->id, "Is sleeping!");
		smart_sleep(philo->gen->sleep_time, philo->gen);
		write_status(philo->gen, philo->id, "Is thinking!");
	}
	return (NULL);
}

void	*thread1(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	write_status(philo->gen, philo->id, "Has taken a fork!");
	usleep(philo->gen->die_time * 1000);
	write_status(philo->gen, philo->id, "died!");
	return (NULL);
}
