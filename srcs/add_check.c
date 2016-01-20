/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:32 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int		ft_check_case2(t_env *env)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (env->game_tab[x][y] != 0)
				z++;
			y++;
		}
		y = 0;
		x++;
	}
	if (z == 2)
		return (1);
	return (0);
}

void			ft_add_in_tab(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			env->game_tab[x][y] = 0;
			y++;
		}
		y = 0;
		x++;
	}
	env->game_tab[rand() % 4][rand() % 4] = (rand() % 2 + 1) * 2;
	env->game_tab[rand() % 4][rand() % 4] = (rand() % 2 + 1) * 2;
	while (ft_check_case2(env) == 0)
		env->game_tab[rand() % 4][rand() % 4] = (rand() % 2 + 1) * 2;
}
