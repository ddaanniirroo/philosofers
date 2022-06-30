/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:20:54 by cprester          #+#    #+#             */
/*   Updated: 2022/06/30 21:21:15 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# define RED "\x1b[31m"
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				id;
	int				how_phil_eat;

	int				corpse;
	int				pid;
	pthread_t		thread;
	unsigned long	time_last_eat;
	struct s_data	*dinner;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;
	sem_t			*fork;
	sem_t			*kill_proc;
	unsigned long	start_time;
	int				numb_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_phil_eat;
}				t_data;

int				check_param(t_data *param);
int				read_argv(char **argv, t_data *param, int argc);
void			sem_init_m(t_data *param);
void			close_sem(t_data *param);
unsigned long	get_time(void);
void			ft_usleep(int time_to_wait);
void			philo_fork(t_data *param, int *pid);
void			fork_kill_pid(t_data *param, int kill_pid, int i, int *pid);
void			philo_create(t_data *param);
int				ft_atoi(const char *str);
void			*check_death(t_philo *philo);
void			print_xiy(t_philo *philo);
void			fork_proc(t_data *param, int i);

#endif
