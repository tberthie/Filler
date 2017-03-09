/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 16:39:55 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#include "libft.h"

#include <unistd.h>

void			event(SDL_Event ev, t_filler *filler)
{
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE)
		filler->run = 0;
}

static char		init(t_filler *filler)
{
	if (!SDL_Init(SDL_INIT_EVERYTHING) && (filler->win =
	SDL_CreateWindow("Filler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	1000, 1200, SDL_WINDOW_BORDERLESS)) && !TTF_Init() && (filler->ren =
	SDL_CreateRenderer(filler->win, -1, SDL_RENDERER_ACCELERATED)) &&
	(filler->font = TTF_OpenFont("font/Bold.otf", 500)))
		return (1);
	return (0);
}

int				main(void)
{
	t_filler	filler;
	SDL_Event	ev;
	char		c;

	filler.run = 1;
	if (init(&filler))
	{
		filler.map = 0;
		filler.player = 0;
		while (filler.run && read(0, &c, 1))
		{
			if (!parse(&filler))
				break ;
			display(&filler);
			SDL_PollEvent(&ev) ? event(ev, &filler) : 0;
		}
		scoreboard(&filler);
	}
	else
		ft_printf(2, "Filler: %s\n", SDL_GetError());
	TTF_Quit();
	SDL_Quit();
	return (0);
}
