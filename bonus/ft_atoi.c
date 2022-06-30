/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:19:14 by cprester          #+#    #+#             */
/*   Updated: 2022/06/30 21:22:29 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	skip_space(const char *str, int *i, int *n)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		++*i;
	if (str[*i] == '-')
	{
		*n = -(*n);
		++*i;
		if (!ft_isdigit(str[*i]))
			return (1);
	}
	if (str[*i] == '+')
	{
		++*i;
		if (!ft_isdigit(str[*i]))
			return (1);
	}
	return (0);
}

int	check_dit(const char *str, int *i)
{
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
			return (1);
		++*i;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			n;
	long int	res;

	i = 0;
	n = 1;
	res = 0;
	if (skip_space(str, &i, &n))
		return (-1);
	j = i;
	if (check_dit(str, &i))
		return (-1);
	while (str[j] >= '0' && str [j] <= '9')
	{
		res = res * 10 + str[j] - '0';
		j++;
		if (res > 2147483647 || res < -2147483648)
			break ;
	}
	return (res * n);
}
