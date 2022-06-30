/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:19:35 by cprester          #+#    #+#             */
/*   Updated: 2022/06/30 21:20:42 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int time_to_wait)
{
	unsigned long	time;

	time = get_time();
	while (get_time() < time + (unsigned long)time_to_wait)
		usleep(100);
}

void	philo_fork(t_data *param, int *pid)
{
	int	i;

	i = 0;
	while (i < param->numb_phil)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			while (i >= 0)
			{
				kill(pid[i], SIGKILL);
				i--;
			}
			exit(EXIT_FAILURE);
		}
		if (pid[i] == 0)
			fork_proc(param, i);
		i++;
	}
}

void	fork_kill_pid(t_data *param, int kill_pid, int i, int *pid)
{
	if (kill_pid == 0)
	{
		sem_wait(param->kill_proc);
		while (i < param->numb_phil)
		{
			kill(pid[i], SIGKILL);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}

void	philo_create(t_data *param)
{
	int	i;
	int	kill_pid;
	int	*pid;

	i = 0;
	pid = malloc(sizeof(int) * param->numb_phil);
	if (!pid)
		exit(EXIT_FAILURE);
	philo_fork(param, pid);
	kill_pid = fork();
	fork_kill_pid(param, kill_pid, i, pid);
	while (i < param->numb_phil)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	kill(kill_pid, SIGKILL);
	free(pid);
}
