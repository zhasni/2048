/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:36 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ft_draw_num(t_env *env, int mod, int i, int y)
{
	env->v = env->index % 4;
	env->v2 = env->index - (env->index % 4) * 4;
	if (i == mod / 4 || i == ((mod * 3) / 4) ||\
			i == ((mod * 5) / 4) || i == ((mod * 7) / 4))
	{
		if (y == env->mod2 / 4 || y == ((env->mod2 * 3) / 4) ||\
				y == ((env->mod2 * 5) / 4) || y == ((env->mod2 * 7) / 4))
		{
			if (env->game_tab[env->v][env->v2] != 0)
			{
				init_pair(1, (env->game_tab[env->v][env->v2] % 7) + 2, 0);
				attron(COLOR_PAIR(1));
				mvprintw(i, y, "%d", env->game_tab[env->v][env->v2]);
				if (env->game_tab[env->v][env->v2] == WIN_VALUE)
					env->win = 1;
				attroff(COLOR_PAIR(1));
			}
			env->index++;
		}
	}
}

int			ft_draw_game(t_env *env)
{
	int		i;
	int		mod;
	int		y;

	i = 0;
	y = 0;
	mod = env->taillel / 2;
	env->mod2 = env->tailleh / 2;
	env->index = 0;
	while (i < env->taillel)
	{
		while (y < env->tailleh)
		{
			ft_draw_num(env, mod, i, y);
			y++;
		}
		y = 0;
		i++;
	}
	return (1);
}
