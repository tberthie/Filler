/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/22 17:24:48 by tberthie         ###   ########.fr       */
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
		piece(&filler);
		insert(&filler);
	}
	return (0);
}
