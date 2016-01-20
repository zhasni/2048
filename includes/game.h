/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:19:17 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define CLEAR "\e[1;1H\e[2J"

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

enum				e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_env
{
	int				tailleh;
	int				taillel;
	char			*l_1;
	char			*l_2;
	char			*l_3;
	char			*l_4;
	int				width;
	int				game_tab[4][4];
	int				game_tab2[4][4];
	int				index;
	int				index2;
	int				startx;
	int				starty;
	int				z;
	int				x;
	int				y;
	int				ch;
	int				v;
	int				v2;
	int				mod2;
	int				loose;
	int				score;
	int				move;
	int				win;
}					t_env;

void				ft_add_in_tab(t_env *env);
int					ft_draw_game(t_env *env);
void				ft_move(t_env *env, int ch);
int					ft_loose(t_env *env);
void				ft_move_up(t_env *env);
void				ft_move_down(t_env *env);
void				ft_move_left(t_env *env);
void				ft_move_right(t_env *env);
void				ft_add_in_tab2(t_env *env);
void				clearscreen(void);

#endif
