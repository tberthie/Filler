/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:56:50 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 18:07:29 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		lock(t_filler *filler, int xb, int yb, int target)
{
	int			x;
	int			y;
	char		cmp;

	if (!filler->target[target])
		return (1);
	y = !yb ? filler->map_y / 2 : (yb == 1) * (filler->map_y - 1);
	x = !xb ? filler->map_x / 2 : (xb == 1) * (filler->map_x - 1);
	cmp = filler->map[x + y * filler->map_x];
	if (cmp == filler->player || cmp == filler->player + 32)
		return (1);
	return (0);
}

void			check_targets(t_filler *filler)
{
	int		target;

	target = -1;
	while (target++ < 7)
	{
		if (!filler->target[target])
			continue ;
		if ((target == 0 && lock(filler, 0, -1, 1) && lock(filler, -1, 0, 3))
		|| (target == 1 && lock(filler, -1, -1, 0) && lock(filler, 1, -1, 2))
		|| (target == 2 && lock(filler, 0, -1, 1) && lock(filler, 1, 0, 4))
		|| (target == 3 && lock(filler, -1, -1, 0) && lock(filler, -1, 1, 5))
		|| (target == 4 && lock(filler, 1, -1, 2) && lock(filler, 1, 1, 7))
		|| (target == 5 && lock(filler, -1, 0, 3) && lock(filler, 0, 1, 6))
		|| (target == 6 && lock(filler, -1, 1, 5) && lock(filler, 1, 1, 7))
		|| (target == 7 && lock(filler, 0, 1, 6) && lock(filler, 1, 0, 4)))
			filler->target[target] = 0;
	}
}
