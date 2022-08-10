/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:13:03 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/07/29 00:01:22 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_my_atoi(const char *nptr)
{
	int	str;
	int	negative;

	negative = 0;
	str = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		str = (str * 10) + (*nptr++ - 48);
	}
	if (negative)
		return (str * -1);
	return (str);
}

int	is_reached_max_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->gen->m_to_eat);
	if (philo->times_eat >= philo->gen->max_eat)
	{
		pthread_mutex_unlock(&philo->gen->m_to_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->gen->m_to_eat);
	return (0);
}
