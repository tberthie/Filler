/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:58 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 17:56:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

static char		insert(t_filler *filler, int x, int y)
{
	int		count;
	char	cmp;
	int		px;
	int		py;

	count = 0;
	py = y + filler->piece_y <= filler->map_y ? filler->piece_y : 0;
	while (py--)
	{
		px = x + filler->piece_x <= filler->map_x ? filler->piece_x : 0;
		while (px--)
		{
			if (filler->piece[px + py * filler->piece_x] == '.')
				continue ;
			cmp = filler->map[px + x + (py + y) * filler->map_x];
			if (cmp == filler->player || cmp == filler->player + 32)
				count++;
			else if (cmp != '.')
				return (0);
		}
	}
	if (count == 1)
		ft_printf(1, "%d %d\n", y - filler->off[1], x - filler->off[0]);
	return (count == 1) ? 1 : 0;
}

static char		check_offset(t_filler *filler, int x, int y, int off)
{
	int		px;
	int		py;

	py = y - off - 1;
	while (py++ < y + off)
	{
		px = x - off - 1;
		while (px++ < x + off)
		{
			if (px >= 0 && py >= 0 && insert(filler, px, py))
				return (1);
		}
	}
	return (0);
}

static char		corner(t_filler *filler, char xb, char yb)
{
	int		y;
	int		x;
	int		off;

	y = !yb ? filler->map_y / 2 : (yb == 1) * (filler->map_y - 1);
	x = !xb ? filler->map_x / 2 : (xb == 1) * (filler->map_x - 1);
	off = 0;
	while (off <= (filler->map_x > filler->map_y ?
	filler->map_x : filler->map_y))
	{
		if (check_offset(filler, x, y, off++))
			return (1);
	}
	return (0);
}

void			fill(t_filler *filler)
{
	char		status;

	if (filler->dir == 0)
		status = corner(filler, -1, -1);
	else if (filler->dir == 1)
		status = corner(filler, 0, -1);
	else if (filler->dir == 2)
		status = corner(filler, 1, -1);
	else if (filler->dir == 3)
		status = corner(filler, -1, 0);
	else if (filler->dir == 4)
		status = corner(filler, 1, 0);
	else if (filler->dir == 5)
		status = corner(filler, -1, 1);
	else if (filler->dir == 6)
		status = corner(filler, 0, 1);
	else if (filler->dir == 7)
		status = corner(filler, 1, 1);
	else
		status = corner(filler, 0, 0);
	if (!status)
		ft_printf(1, "0 0\n");
	check_targets(filler);
	filler->dir = filler->dir == 7 ? 0 : filler->dir + 1;
}
