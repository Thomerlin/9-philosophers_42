/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:10:36 by tyago-ri          #+#    #+#             */
/*   Updated: 2022/08/20 17:11:42 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(char *string)
{
	printf("Error: %s\n", string);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_gen	gen;

	if (argc < 5 || argc > 6)
		return (print_error("Wrong number of arguments!"));
	if (!init_all(&gen, argc, argv))
	{
		finish2(&gen);
		return (0);
	}
	threading(&gen);
	finish(&gen);
	return (0);
}
