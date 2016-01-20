/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 12:13:58 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/17 12:31:33 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap(char *s1, char *s2)
{
	char	*bkp;

	bkp = NULL;
	bkp = s1;
	s1 = s2;
	s2 = bkp;
}