/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:34 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int		ft_chack_tab(t_env *env)
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
	if (z == 16)
		return (1);
	return (0);
}

void			ft_add_in_tab2(t_env *env)
{
	int		x2;
	int		y2;

	x2 = rand() % 4;
	y2 = rand() % 4;
	while (env->game_tab[x2][y2] != 0 && ft_chack_tab(env) == 0)
	{
		x2 = rand() % 4;
		y2 = rand() % 4;
	}
	if (ft_chack_tab (env) == 0)
		env->game_tab[x2][y2] = (rand() % 2 + 1) * 2;
}
