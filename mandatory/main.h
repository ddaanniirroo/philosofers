/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:39:22 by cprester          #+#    #+#             */
/*   Updated: 2022/06/30 21:22:04 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_phylo {
	int					index_phylo;
	int					eat_times;
	long long			time_eating;
	int					fork_left;
	int					fork_right;
	pthread_t			thread;
	struct s_init		*data;
}	t_phylo;

typedef struct s_init {
	long long		start_time;
	int				number_of_philosophers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				times_each_p_must_eat;
	int				phylo_dead;
	int				fed_phylo;
	pthread_mutex_t	*fork;
	t_phylo			*init_p;
}	t_init;

int				ft_init(int argc, char **argv, t_init *init);
int				ft_atoi(const char	*str);
int				ft_check_numbers(char **argv);
int				ft_check_phylo(t_init *init);
int				ft_init_phylo(t_init *init);
void			ft_create_pthread(t_init *init);
void			ft_join_mutex_lock(t_init *init);
unsigned long	get_time(void);
void			ft_live(t_phylo *init);
int				ft_phylo_dead(t_init *init);

#endif
