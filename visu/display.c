/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:27:34 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/08 17:15:56 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#include "libft.h"

static void		render_map(t_filler *filler)
{
	int			x;
	int			y;
	char		c;

	y = 0;
	filler->score_o = 1;
	filler->score_x = 1;
	while (y < (int)ft_strlen(filler->map) / filler->map_x)
	{
		x = 0;
		while (x < filler->map_x)
		{
			c = filler->map[x + y * filler->map_x];
			filler->score_o += (c == 'O' || c == 'o');
			filler->score_x += (c == 'X' || c == 'x');
			SDL_SetRenderDrawColor(filler->ren, 25, 25, 25, 255);
			c == 'O' ? SDL_SetRenderDrawColor(filler->ren, 150, 0, 0, 255) : 0;
			c == 'o' ? SDL_SetRenderDrawColor(filler->ren, 255, 0, 0, 255) : 0;
			c == 'X' ? SDL_SetRenderDrawColor(filler->ren, 0, 0, 150, 255) : 0;
			c == 'x' ? SDL_SetRenderDrawColor(filler->ren, 0, 0, 255, 255) : 0;
			draw_rect(filler, x++, y);
		}
		y++;
	}
}

static void		bar(t_filler *filler)
{
	int		ratio;
	int		max;
	int		i;

	max = filler->score_x + filler->score_o;
	ratio = (int)(920.0 * filler->score_o / max);
	SDL_SetRenderDrawColor(filler->ren, 255, 0, 0, 255);
	i = 0;
	while (i < ratio)
	{
		SDL_RenderDrawLine(filler->ren, 40 + i, 180, 40 + i, 200);
		i++;
	}
	SDL_SetRenderDrawColor(filler->ren, 0, 0, 255, 255);
	while (i < 920)
	{
		SDL_RenderDrawLine(filler->ren, 40 + i, 180, 40 + i, 200);
		i++;
	}
}

static void		outlines(t_filler *filler)
{
	SDL_SetRenderDrawColor(filler->ren, 255, 255, 255, 255);
	SDL_RenderDrawLine(filler->ren, 20, 220, 20, 1180);
	SDL_RenderDrawLine(filler->ren, 980, 220, 980, 1180);
	SDL_RenderDrawLine(filler->ren, 20, 220, 980, 220);
	SDL_RenderDrawLine(filler->ren, 20, 1180, 980, 1180);
}

void			display(t_filler *filler)
{
	SDL_SetRenderDrawColor(filler->ren, 0, 0, 0, 255);
	SDL_RenderClear(filler->ren);
	render_map(filler);
	bar(filler);
	render_score(filler);
	outlines(filler);
	SDL_RenderPresent(filler->ren);
}
