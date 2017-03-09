/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:09:45 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 15:27:54 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

char			insert(t_filler *filler, int x, int y)
{
	int		count;
	char	cmp;
	int		px;
	int		py;

	count = 0;
	if (x + filler->piece_x > filler->map_x
	|| y + filler->piece_y > filler->map_y)
		return (0);
	py = filler->piece_y;
	while (py--)
	{
		px = filler->piece_x;
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
