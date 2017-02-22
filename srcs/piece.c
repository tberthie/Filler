/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:20:16 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/22 17:50:15 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

#include <stdlib.h>

static void		clean(t_filler *filler)
{
	int		x;
	int		y;

	filler->off_x = filler->piece_x;
	y = (int)ft_strlen(filler->piece) / filler->piece_x;
	filler->off_y = y;
	while (y--)
	{
		x = filler->piece_x;
		while (x--)
			if (filler->piece[x + y * filler->piece_x] == '*')
			{
				filler->off_x = filler->off_x > x ? x : filler->off_x;
				filler->off_y = filler->off_y > y ? y : filler->off_y;
			}
	}
}

void			piece(t_filler *filler)
{
	char			*line;
	char			**split;
	unsigned int	i;
	unsigned int	j;

	line = ft_gnl(0);
	split = ft_strsplit(line, ' ');
	free(line);
	filler->piece_x = ft_atoi(split[2]);
	filler->piece = (char*)ft_memalloc(sizeof(char) *
	(i = (unsigned int)(ft_atoi(split[1]) * filler->piece_x + 1)));
	ft_parrfree((void**)split);
	--i;
	while (i--)
		filler->piece[i] = '.';
	i = 0;
	while (i < ft_strlen(filler->piece))
	{
		line = ft_gnl(0);
		j = 0;
		while (line[j])
			filler->piece[i++] = line[j++];
		free(line);
	}
	clean(filler);
}
