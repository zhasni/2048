/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:15:04 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ft_check_line_left(t_env *env)
{
	int x;
	int y;
	int swap;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (env->game_tab[y][x] == 0 &&\
					env->game_tab[y][x + 1] != 0 && (x + 1) < 4)
			{
				swap = env->game_tab[y][x + 1];
				env->game_tab[y][x + 1] = env->game_tab[y][x];
				env->game_tab[y][x] = swap;
				x = 0;
			}
			else
				x++;
		}
		y++;
	}
}

void		ft_move_left(t_env *env)
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
			ft_check_line_left(env);
			if (env->game_tab[y][x] == env->game_tab[y][x + 1])
			{
				env->game_tab[y][x] *= 2;
				env->score += env->game_tab[y][x];
				env->game_tab[y][x + 1] = 0;
			}
			x++;
		}
		y++;
	}
}
