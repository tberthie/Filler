/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:21:51 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/08 12:13:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

static char		check(t_filler *filler, int *x, int *y)
{
	if (x[0] <= filler->map_x - filler->piece_x && y[0] <=
	(int)ft_strlen(filler->map) / filler->map_x - (int)ft_strlen(filler->piece)
	/ filler->piece_x && fits(x[0], y[0], filler))
		ft_printf(1, "%d %d\n", y[0] - filler->off[1], x[0] - filler->off[0]);
	else if (x[0] <= filler->map_x - filler->piece_x && y[1] >= 0
	&& fits(x[0], y[1], filler))
		ft_printf(1, "%d %d\n", y[1] - filler->off[1], x[0] - filler->off[0]);
	else if (x[1] >= 0 && y[0] <= (int)ft_strlen(filler->map) / filler->map_x -
	(int)ft_strlen(filler->piece) / filler->piece_x && fits(x[1], y[0], filler))
		ft_printf(1, "%d %d\n", y[0] - filler->off[1], x[1] - filler->off[0]);
	else if (x[1] >= 0 && y[1] >= 0 && fits(x[1], y[1], filler))
		ft_printf(1, "%d %d\n", y[1] - filler->off[1], x[1] - filler->off[0]);
	else
		return (0);
	return (1);
}

static void		lock_vertical(t_filler *filler)
{
	int		x[2];
	int		y[2];

	x[0] = filler->map_x / 2;
	x[1] = x[0];
	while (x[0] <= filler->map_x - filler->piece_x || x[1] >= 0)
	{
		y[0] = (int)ft_strlen(filler->map) / filler->map_x / 2;
		y[1] = y[0];
		while ((y[0] <= (int)ft_strlen(filler->map) / filler->map_x -
		(int)ft_strlen(filler->piece) / filler->piece_x || y[1] >= 0))
		{
			if (check(filler, x, y))
				return ;
			y[0]++;
			y[1]--;
		}
		x[0]++;
		x[1]--;
	}
	ft_putstr("0 0\n");
}

static void		lock_horizontal(t_filler *filler)
{
	int		x[2];
	int		y[2];

	y[0] = (int)ft_strlen(filler->map) / filler->map_x / 2;
	y[1] = y[0];
	while ((y[0] <= (int)ft_strlen(filler->map) / filler->map_x -
	(int)ft_strlen(filler->piece) / filler->piece_x || y[1] >= 0))
	{
		x[0] = filler->map_x / 2;
		x[1] = x[0];
		while (x[0] <= filler->map_x - filler->piece_x || x[1] >= 0)
		{
			if (check(filler, x, y))
				return ;
			x[0]++;
			x[1]--;
		}
		y[0]++;
		y[1]--;
	}
	ft_putstr("0 0\n");
}

void			lock(t_filler *filler, char dir)
{
	if (dir)
		lock_horizontal(filler);
	else
		lock_vertical(filler);
}
