/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:39 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void draw_grid2(int y_max, int x_max, t_env *env)
{
	init_pair(2, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(2));
	border('|', '|', '-', '-', '+', '+', '+', '+');
	mvhline(y_max / 2, 0 + 1, '-', x_max - 2);
	mvhline(y_max / 4, 0 + 1, '-', x_max - 2);
	mvhline((y_max / 2) + (y_max / 4), 0 + 1, '-', x_max - 2);
	mvvline(0 + 1, (x_max / 2), '|', (y_max) - 2);
	mvvline(0 + 1, (x_max / 4), '|', (y_max) - 2);
	mvvline(0 + 1, ((x_max / 2) + (x_max / 4)), '|', (y_max) - 2);
	attroff(COLOR_PAIR(2));
	init_pair(3, COLOR_BLACK, COLOR_RED);
	attron(COLOR_PAIR(3));
	if (env->win == 1)
		mvprintw(y_max / 2, x_max / 2, "You Win");
	mvprintw(y_max - 1, x_max / 2, "Score : %d", env->score);
	mvprintw(y_max - 1, x_max / 4, "Coups : %d", env->move);
	attroff(COLOR_PAIR(3));
}

static int	win_gestion(void)
{
	int		i;

	i = 2;
	while (i < WIN_VALUE)
	{
		i = i << 1;
	}
	if (i == WIN_VALUE)
		return (1);
	return (0);
}

static void	error_gestion(void)
{
	if (WIN_VALUE <= 2 || win_gestion() == 0)
	{
		ft_putstr("Bad WIN VALUE");
		exit(0);
	}
}

static void	ft_init(t_env *env)
{
	env->win = 0;
	env->loose = 0;
	env->score = 0;
	env->move = 0;
	initscr();
	noecho();
	error_gestion();
	start_color();
	curs_set(0);
	srand(time(NULL));
	ft_add_in_tab(env);
	keypad(stdscr, TRUE);
	env->taillel = 10;
	env->ch = 'l';
	env->index = 0;
}

int			main(void)
{
	t_env	env;

	ft_init(&env);
	while (env.ch != '\033' && env.taillel >= 9 && env.loose != 1)
	{
		getmaxyx(stdscr, env.taillel, env.tailleh);
		getyx(stdscr, env.x, env.y);
		ft_draw_game(&env);
		draw_grid2(env.taillel, env.tailleh, &env);
		env.ch = getch();
		ft_move(&env, env.ch);
		refresh();
		clear();
	}
	curs_set(1);
	clearscreen();
	endwin();
	if (env.taillel < 9)
		ft_putstr("\n\nTo little window\n");
	if (env.loose == 1)
		ft_putstr("\n\nYou loose !!!!\n\n");
	return (0);
}
