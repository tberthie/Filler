/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:58 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 15:35:39 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "libft.h"

void			fill(t_filler *filler)
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
				return ;
		}
	}
	ft_printf(1, "0 0\n");
}
