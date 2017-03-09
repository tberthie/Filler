/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:39:52 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 17:03:07 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

#include <stdlib.h>

static void		cut_piece(t_filler *filler, int *off_x, int *off_y)
{
	int			x;
	int			y;
	char		*piece;

	piece = (char*)ft_m(sizeof(char) * (ft_strlen(filler->piece) + 1));
	y = off_y[0];
	while (y <= off_y[1])
	{
		x = off_x[0];
		while (x <= off_x[1])
		{
			piece[x - off_x[0] + (y - off_y[0]) * (off_x[1] - off_x[0] + 1)] =
			filler->piece[x + y * filler->piece_x];
			x++;
		}
		y++;
	}
	free(filler->piece);
	filler->piece = piece;
	filler->piece_x = off_x[1] - off_x[0] + 1;
	filler->piece_y = off_y[1] - off_y[0] + 1;
	filler->off[0] = off_x[0];
	filler->off[1] = off_y[0];
}

static void		clean_piece(t_filler *filler)
{
	int		off_x[2];
	int		off_y[2];
	int		i;

	i = 0;
	while (filler->piece[i] != '*')
		i++;
	off_y[0] = i / filler->piece_x;
	off_y[1] = i / filler->piece_x;
	off_x[0] = i % filler->piece_x;
	off_x[1] = i % filler->piece_x;
	while (filler->piece[i])
	{
		if (filler->piece[i] == '*')
		{
			off_y[1] = i / filler->piece_x;
			if (i % filler->piece_x < off_x[0])
				off_x[0] = i % filler->piece_x;
			if (i % filler->piece_x > off_x[1])
				off_x[1] = i % filler->piece_x;
		}
		i++;
	}
	cut_piece(filler, off_x, off_y);
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
	clean_piece(filler);
}
