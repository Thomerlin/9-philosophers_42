/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:53:20 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/08/10 19:00:31 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_gen_mutex(t_gen *gen)
{
	if (pthread_mutex_init(&gen->m_meal, NULL))
		return (print_error("Mutex initialization failed."));
	if (pthread_mutex_init(&gen->m_write, NULL))
		return (print_error("Mutex initialization failed."));
	if (pthread_mutex_init(&gen->m_dead, NULL))
		return (print_error("Mutex initialization failed."));
	if (pthread_mutex_init(&gen->m_fork, NULL))
		return (print_error("Mutex initialization failed."));
	if (pthread_mutex_init(&gen->m_win, NULL))
		return (print_error("Mutex initialization failed."));
	if (pthread_mutex_init(&gen->m_to_eat, NULL))
		return (print_error("Mutex initialization failed."));
	return (1);
}

static int	init_mutex(t_gen *gen)
{
	int	i;

	i = -1;
	gen->fork = malloc(sizeof(t_fork) * gen->philo_count);
	if (gen->fork == NULL)
		return (print_error("Malloc failed!"));
	while (++i < gen->philo_count)
	{
		if (pthread_mutex_init(&gen->fork[i].mutex, NULL))
			return (print_error("Mutex init failed!"));
		gen->fork[i].taken = 0;
		gen->fork[i].taken_by = 0;
	}
	return (init_gen_mutex(gen));
}

static int	philosophers_init(t_gen *gen)
{
	int	i;

	i = -1;
	gen->philo = malloc(sizeof(t_philo) * gen->philo_count);
	if (gen->philo == NULL)
		return (print_error("Malloc failed!"));
	while (++i < gen->philo_count)
	{
		gen->philo[i].id = i + 1;
		gen->philo[i].times_eat = 0;
		gen->philo[i].right = i;
		gen->philo[i].left = (i + 1) % gen->philo_count;
		gen->philo[i].last_meal = 0;
		gen->philo[i].gen = gen;
	}
	return (1);
}

int	init_all(t_gen *gen, int argc, char **argv)
{
	gen->philo_count = ft_my_atoi(argv[1]);
	gen->die_time = ft_my_atoi(argv[2]);
	gen->eat_time = ft_my_atoi(argv[3]);
	gen->sleep_time = ft_my_atoi(argv[4]);
	gen->max_eat = -1;
	if (argc == 6)
		gen->max_eat = ft_my_atoi(argv[5]);
	gen->died = 0;
	gen->win = 0;
	if (gen->philo_count < 1 || gen->die_time < 0 || gen ->eat_time < 0
		|| gen->sleep_time < 0 || (argc == 6 && gen->max_eat < 1))
		return (print_error("Argument invalid!"));
	return (init_mutex(gen) * philosophers_init(gen));
}
