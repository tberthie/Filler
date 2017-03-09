/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 14:58:46 by tberthie         ###   ########.fr       */
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

	filler.map = 0;
	filler.piece = 0;
	filler.player = 0;
	while (read(0, &c, 1))
	{
		parse(&filler);
		ft_printf(2, "MAP %d %d\n", filler.map_x, filler.map_y);
		ft_printf(2, "PIE %d %d\n", filler.piece_x, filler.piece_y);
		fill(&filler);
	}
	return (0);
}
