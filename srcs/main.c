/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/08 16:24:37 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

int				main(void)
{
	t_filler	filler;
	char		c;
	char		dir;

	dir = 0;
	filler.pos_y = -1;
	filler.map = 0;
	filler.piece = 0;
	filler.player = 0;
	while (read(0, &c, 1))
	{
		parse(&filler);
		lock(&filler, locked(&filler) ? dir : 0);
		dir = dir ? 0 : 1;
	}
	return (0);
}
