/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:45 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ft_check_column_up(t_env *env)
{
	int x;
	int y;
	int swap;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (env->game_tab[y][x] == 0 &&\
					env->game_tab[y + 1][x] != 0 && (y + 1) < 4)
			{
				swap = env->game_tab[y + 1][x];
				env->game_tab[y + 1][x] = env->game_tab[y][x];
				env->game_tab[y][x] = swap;
				y = 0;
			}
			else
				y++;
		}
		x++;
	}
}

void		ft_move_up(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			ft_check_column_up(env);
			if (env->game_tab[y][x] == env->game_tab[y + 1][x])
			{
				env->game_tab[y][x] *= 2;
				env->score += env->game_tab[y][x];
				env->game_tab[y + 1][x] = 0;
			}
			y++;
		}
		x++;
	}
}
