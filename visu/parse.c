/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:29:53 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 13:10:46 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#include "libft.h"

#include <stdlib.h>

static void		skip(int nb)
{
	char	*line;

	while (nb--)
	{
		line = ft_gnl(0);
		free(line);
	}
}

static void		create_map(t_filler *filler)
{
	char			*line;
	char			**split;
	unsigned int	i;

	skip(9);
	line = ft_gnl(0);
	split = ft_strsplit(line, ' ');
	free(line);
	filler->map_x = ft_atoi(split[2]);
	filler->map = (char*)ft_memalloc(sizeof(char) *
	(i = (unsigned int)(filler->map_x * ft_atoi(split[1]) + 1)));
	--i;
	while (i--)
		filler->map[i] = '.';
	filler->dim[0] = 920.0 / filler->map_x;
	filler->dim[1] = 920.0 / (ft_strlen(filler->map) / filler->map_x);
	ft_parrfree((void**)split);
	skip(1);
}

static char		allign_read(t_filler *filler)
{
	char		*line;

	if (!filler->map)
		create_map(filler);
	else
	{
		while ((line = ft_gnl(0)) && ft_strncmp(line, "Plateau", 7))
			free(line);
		if (line)
		{
			free(line);
			skip(1);
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

char			parse(t_filler *filler)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	if (!allign_read(filler))
		return (0);
	i = 0;
	while (i < ft_strlen(filler->map))
	{
		line = ft_gnl(0);
		j = 4;
		while (line[j])
		{
			if (filler->pos_y == -1 && line[j] == filler->player)
				filler->pos_y = (int)i / filler->map_x;
			filler->map[i++] = line[j++];
		}
		free(line);
	}
	if (filler->piece)
		free(filler->piece);
	piece(filler);
	return (1);
}
