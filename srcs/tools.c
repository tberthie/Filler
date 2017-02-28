/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:45:39 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/26 16:15:25 by tberthie         ###   ########.fr       */
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
