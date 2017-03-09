/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 17:56:30 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

static void		init(t_filler *filler)
{
	int		i;

	filler->map = 0;
	filler->piece = 0;
	filler->player = 0;
	filler->dir = 0;
	i = 0;
	while (i < 8)
		filler->target[i++] = 1;
}

int				main(void)
{
	t_filler	filler;
	int			tmp;
	char		c;

	init(&filler);
	while (read(0, &c, 1))
	{
		parse(&filler);
		fill(&filler);
		tmp = filler.dir;
		while (filler.dir != -1 && !filler.target[filler.dir])
		{
			filler.dir = filler.dir == 7 ? 0 : filler.dir + 1;
			filler.dir = filler.dir == tmp ? -1 : filler.dir;
		}
	}
	return (0);
}
