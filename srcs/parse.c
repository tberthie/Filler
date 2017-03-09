/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:29:53 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 14:59:02 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

	line = ft_gnl(0);
	split = ft_strsplit(line, ' ');
	free(line);
	filler->map_x = ft_atoi(split[2]);
	filler->map_y = ft_atoi(split[1]);
	filler->map = (char*)ft_memalloc(sizeof(char) *
	(i = (unsigned int)(filler->map_x * ft_atoi(split[1]) + 1)));
	--i;
	while (i--)
		filler->map[i] = '.';
	ft_parrfree((void**)split);
	skip(1);
}

static void		parse_player(t_filler *filler)
{
	char		*line;
	char		**split;

	line = ft_gnl(0);
	split = ft_strsplit(line, ' ');
	free(line);
	if (!ft_strcmp(split[2], "p1"))
		filler->player = 'O';
	else
		filler->player = 'X';
	ft_parrfree((void**)split);
}

void			parse(t_filler *filler)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	if (!filler->player)
		parse_player(filler);
	!filler->map ? create_map(filler) : skip(2);
	i = 0;
	while (i < ft_strlen(filler->map))
	{
		line = ft_gnl(0);
		j = 4;
		while (line[j])
			filler->map[i++] = line[j++];
		free(line);
	}
	if (filler->piece)
		free(filler->piece);
	piece(filler);
}
