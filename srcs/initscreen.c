/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:12:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/01 23:16:37 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void			clearscreen(void)
{
	char	*clear;

	clear = CLEAR;
	write(STDOUT_FILENO, clear, 12);
}
