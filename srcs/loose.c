/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:38 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int		ft_loose(t_env *env)
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
			if (env->game_tab[y][x] == env->game_tab[y][x + 1] && (x + 1) < 4)
				return (1);
			if (env->game_tab[y][x] == env->game_tab[y + 1][x] && (y + 1) < 4)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
