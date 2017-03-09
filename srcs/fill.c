/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:58 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 15:53:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

char			random(t_filler *filler)
{
	int		y;
	int		x;

	y = filler->map_y;
	while (y--)
	{
		x = filler->map_x;
		while (x--)
		{
			if (insert(filler, x, y))
				return (1);
		}
	}
	return (0);
}

void			fill(t_filler *filler)
{
	char		status;

	/**/
	status = random(filler);
	/**/
	if (!status)
		ft_printf(1, "0 0\n");
}
