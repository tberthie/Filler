/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:29:33 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/22 18:19:57 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

static char		fits(int x, int y, t_filler *filler)
{
	char	cmp;
	int		count;
	int		px;
	int		py;

	count = 0;
	py = filler->off_y;
	while (py < (int)ft_strlen(filler->piece) / filler->piece_x)
	{
		px = filler->off_x;
		while (px < filler->piece_x)
		{
			cmp = filler->map[x + px + (y + py) * filler->map_x];
			if ((cmp == 'O' && filler->player == 'O')
			|| (cmp == 'X' && filler->player == 'X'))
				count++;
			else if (cmp == 'O' || cmp == 'X')
				return (0);
			px++;
		}
		py++;
	}
	ft_printf(2, "%d\n", count);
	return (count != 1) ? 0 : 1;
}

void			insert(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y + ((int)ft_strlen(filler->piece) / filler->piece_x) - filler->off_y <
	(int)ft_strlen(filler->map) / filler->map_x)
	{
		x = 0;
		while (x + filler->piece_x - filler->off_x < filler->map_x)
		{
			ft_printf(2, "%d %d\n", x, y);
			if (fits(x, y, filler))
			{
				ft_printf(1, "%d %d\n", y - filler->off_y, x - filler->off_x);
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putstr("0 0\n");
}
