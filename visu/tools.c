/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:10:08 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 14:44:33 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void				draw_rect(t_filler *filler, int x, int y)
{
	int			i;
	int			px;
	int			py;

	i = 0;
	px = (int)(x * filler->dim[0]) + 40;
	py = (int)(y * filler->dim[1]) + 240;
	while (i < filler->dim[1])
	{
		SDL_RenderDrawLine(filler->ren, px, py + i, px
		+ filler->dim[0], py + i);
		i++;
	}
}

SDL_Texture			*get_text(t_filler *filler, char *text)
{
	SDL_Surface		*sf;
	SDL_Texture		*tx;
	SDL_Color		color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	sf = TTF_RenderText_Solid(filler->font, text, color);
	tx = SDL_CreateTextureFromSurface(filler->ren, sf);
	SDL_FreeSurface(sf);
	return (tx);
}

SDL_Rect			get_rect(int x, int y, int w, int h)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}
