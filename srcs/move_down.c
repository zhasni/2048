/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:41 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ft_check_column_down(t_env *env)
{
	int x;
	int y;
	int swap;

	y = 3;
	x = 0;
	while (x < 4)
	{
		y = 3;
		while (y > -1)
		{
			if (env->game_tab[y][x] == 0 &&\
					env->game_tab[y - 1][x] != 0 && (y - 1) > -1)
			{
				swap = env->game_tab[y][x];
				env->game_tab[y][x] = env->game_tab[y - 1][x];
				env->game_tab[y - 1][x] = swap;
				y = 3;
			}
			else
				y--;
		}
		x++;
	}
}

void		ft_move_down(t_env *env)
{
	int		x;
	int		y;

	y = 3;
	x = 0;
	while (x < 4)
	{
		y = 3;
		while (y > -1)
		{
			ft_check_column_down(env);
			if (env->game_tab[y][x] == env->game_tab[y - 1][x])
			{
				env->game_tab[y][x] *= 2;
				env->score += env->game_tab[y][x];
				env->game_tab[y - 1][x] = 0;
			}
			y--;
		}
		x++;
	}
}
