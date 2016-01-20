/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:44 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ft_check_line_right(t_env *env)
{
	int x;
	int y;
	int swap;

	x = 3;
	y = 0;
	while (y < 4)
	{
		x = 3;
		while (x > -1)
		{
			if (env->game_tab[y][x] == 0 &&\
					env->game_tab[y][x - 1] != 0 && (x - 1) > -1)
			{
				swap = env->game_tab[y][x];
				env->game_tab[y][x] = env->game_tab[y][x - 1];
				env->game_tab[y][x - 1] = swap;
				x = 3;
			}
			else
				x--;
		}
		y++;
	}
}

void		ft_move_right(t_env *env)
{
	int		x;
	int		y;

	x = 3;
	y = 0;
	while (y < 4)
	{
		x = 3;
		while (x > -1)
		{
			ft_check_line_right(env);
			if (env->game_tab[y][x] == env->game_tab[y][x - 1])
			{
				env->game_tab[y][x] *= 2;
				env->score += env->game_tab[y][x];
				env->game_tab[y][x - 1] = 0;
			}
			x--;
		}
		y++;
	}
}
