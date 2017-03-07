/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:45:39 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/07 17:15:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

char		fits(int x, int y, t_filler *filler)
{
	int			px;
	int			py;
	int			count;
	char		cmp;

	count = 0;
	py = 0;
	while (py < (int)ft_strlen(filler->piece) / filler->piece_x)
	{
		px = 0;
		while (px < filler->piece_x)
		{
			if (filler->piece[px + py * filler->piece_x] == '*')
			{
				cmp = filler->map[x + px + (y + py) * filler->map_x];
				if (filler->player == cmp)
					count++;
				else if (cmp == 'O' || cmp == 'X')
					return (0);
			}
			px++;
		}
		py++;
	}
	return (count != 1) ? 0 : 1;
}

char		locked(t_filler *filler)
{
	int		dst[2];
	int		x;
	int		y;

	dst[0] = (int)(filler->map_x * 0.1);
	dst[1] = (int)((int)ft_strlen(filler->map) / filler->map_x * 0.1);
	y = (int)ft_strlen(filler->map) / filler->map_x / 2 - dst[1];
	while (y < (int)ft_strlen(filler->map) / filler->map_x / 2 + dst[1])
	{
		x = filler->map_x / 2 - dst[0];
		while (x < filler->map_x / 2 + dst[0])
		{
			if (filler->map[x + y * filler->map_x] == filler->player)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
