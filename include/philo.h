/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:23:23 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/08/10 19:00:56 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				taken;
	int				taken_by;
}					t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				times_eat;
	int				left;
	int				right;
	long int		last_meal;
	struct s_gen	*gen;
}					t_philo;

typedef struct s_gen
{
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	int				died;
	int				win;
	long int		start_time;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_win;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	m_to_eat;
	t_philo			*philo;
	t_fork			*fork;
}					t_gen;

int			main(int argc, char **argv);
int			print_error(char *string);

void		finish(t_gen *gen);
void		finish2(t_gen *gen);

int			init_all(t_gen *gen, int argc, char **argv);

int			take_fork(t_philo *philo, t_fork *fork);
void		release_fork(t_fork *fork);

int			ft_my_atoi(const char *nptr);

void		*thread(void *input);
void		*thread1(void *input);

void		threading(t_gen *gen);

int			is_reached_max_eat(t_philo *philo);
void		write_status(t_gen *gen, int id, char *str);
long int	get_real_time(void);
void		smart_sleep(long int time, t_gen *gen);
int			check_died(t_gen *gen);
int			check_win(t_gen *gen);

#endif