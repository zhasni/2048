/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:40 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void			ft_init(t_env *env)
{
	ft_add_in_tab(env);
	env->score = 0;
	env->move = 0;
}

static void			ft_cpy_tab(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			env->game_tab2[x][y] = env->game_tab[x][y];
			x++;
		}
		y++;
	}
}

static int			ft_check_tab2(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (env->game_tab2[x][y] == env->game_tab[x][y])
				x++;
			else
				return (1);
		}
		y++;
	}
	return (0);
}

static int			ft_check_tab3(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (env->game_tab[x][y] > 0)
				x++;
			else
				return (1);
		}
		x = 0;
		y++;
	}
	return (0);
}

void				ft_move(t_env *env, int ch)
{
	ft_cpy_tab(env);
	if (ft_check_tab3(env) == 0 && ft_loose(env) == 0)
		env->loose = 1;
	if (ch == 'w')
		ft_move_up(env);
	else if (ch == 'a')
		ft_move_left(env);
	else if (ch == 'd')
		ft_move_right(env);
	if (ch == 's')
		ft_move_down(env);
	if (ch == 'r')
		ft_init(env);
	if ((ch == 's' || ch == 'a' || ch == 'd' || ch == 'w') &&\
			ft_check_tab2(env) == 1)
	{
		env->move++;
		ft_add_in_tab2(env);
	}
}
