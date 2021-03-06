/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 11:43:21 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/17 11:59:15 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_remove_space(char *cmd)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			while (cmd[j] == ' ' || cmd[j] == '\t')
				j++;
			cmd[i] = cmd[j];
			i++;
			j++;
		}
		cmd[i] = '\0';
	}
}
