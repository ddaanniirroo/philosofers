/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:39:19 by cprester          #+#    #+#             */
/*   Updated: 2022/06/30 21:22:12 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_phylo_dead(t_init *init)
{
	long long	time;
	int			i;

	i = 0;
	while (1)
	{
		while (i < init->number_of_philosophers)
		{
			time = get_time();
			if (init->init_p[i].eat_times
				== init->times_each_p_must_eat)
				return (1);
			if (time - init->init_p[i].time_eating
				>= init->time_to_die)
			{
				init->phylo_dead = 1;
				printf ("%llu %d phylo dead\n", time - init->start_time, i + 1);
				return (1);
			}
			i ++;
		}
		i = 0;
		usleep(1000);
	}
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	user_usleep(int time_to_wait)
{
	unsigned long	time;

	time = get_time();
	while (get_time() < time + (unsigned long)time_to_wait)
		usleep(100);
}

void	ft_live(t_phylo *init)
{
	while (init->eat_times
		!= init->data->times_each_p_must_eat && init->data->phylo_dead != 1)
	{
		pthread_mutex_lock (&init->data->fork[init->fork_left]);
		printf ("%llu %d taking left fork\n", get_time()
			- init->data->start_time, init->index_phylo);
		pthread_mutex_lock (&init->data->fork[init->fork_right]);
		printf ("%llu %d taking right fork\n", get_time()
			- init->data->start_time, init->index_phylo);
		printf ("%llu %d eat\n", get_time()
			- init->data->start_time, init->index_phylo);
		user_usleep(init->data->time_to_eat);
		init->time_eating = get_time();
		pthread_mutex_unlock (&init->data->fork[init->fork_left]);
		pthread_mutex_unlock (&init->data->fork[init->fork_right]);
		if (init->eat_times != init->data->times_each_p_must_eat)
		{
			printf ("%llu %d sleep\n", get_time()
				- init->data->start_time, init->index_phylo);
			user_usleep(init->data->time_to_sleep);
			printf ("%llu %d thinking\n", get_time()
				- init->data->start_time, init->index_phylo);
		}
		init->eat_times ++;
	}
}
