/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:39:19 by wmozella          #+#    #+#             */
/*   Updated: 2022/06/02 20:06:35 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_init(int argc, char **argv, t_init *init)
{
	if (ft_check_numbers(argv) == 0)
	{
		init->number_of_philosophers = ft_atoi(argv[1]);
		init->time_to_eat = ft_atoi(argv[3]);
		init->time_to_die = ft_atoi(argv[2]);
		init->time_to_sleep = ft_atoi(argv[4]);
		init->phylo_dead = 0;
		if (argc == 6)
			init->times_each_p_must_eat = ft_atoi(argv[5]);
		else
			init->times_each_p_must_eat = -1;
	}
	return (ft_check_phylo(init));
}

int	ft_init_phylo(t_init *init)
{
	int	i;

	init->init_p = malloc(sizeof(t_phylo) * init->number_of_philosophers);
	if (init->init_p == NULL)
		return (0);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->number_of_philosophers);
	if (init->fork == NULL)
		return (0);
	i = 0;
	while (i < init->number_of_philosophers)
	{
		pthread_mutex_init(&init->fork[i], NULL);
		init->init_p[i].data = init;
		init->init_p[i].index_phylo = i + 1;
		init->init_p[i].fork_right = i;
		if (i == 0)
			init->init_p[i].fork_left = init->number_of_philosophers - 1;
		else
			init->init_p[i].fork_left = i - 1;
		init->init_p[i].eat_times = 0;
		init->init_p[i].time_eating = get_time();
		i ++;
	}
	return (0);
}

void	ft_create_pthread(t_init *init)
{
	int			i;

	i = 0;
	while (i < init->number_of_philosophers)
	{
		pthread_create(&init->init_p[i].thread, NULL, (void *)ft_live,
			&init->init_p[i]);
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < init->number_of_philosophers)
	{
		pthread_create(&init->init_p[i].thread, NULL, (void *)ft_live,
			&init->init_p[i]);
		i += 2;
	}
}

void	ft_join_mutex_lock(t_init *init)
{
	int	i;

	i = 0;
	if (ft_phylo_dead(init))
		return ;
	while (i < init->number_of_philosophers)
	{
		pthread_join(init->init_p[i].thread, NULL);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_init		init;
	int			i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		printf ("Wrong set of arguments\n");
		return (1);
	}
	if (ft_init(argc, argv, &init) == 1)
		return (2);
	init.start_time = get_time();
	ft_init_phylo(&init);
	ft_create_pthread(&init);
	ft_join_mutex_lock(&init);
	free(init.fork);
	free(init.init_p);
	while (i < init.number_of_philosophers)
	{
		pthread_mutex_destroy(&init.fork[i]);
		i ++;
	}
}
