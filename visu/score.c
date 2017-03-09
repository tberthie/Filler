/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:21:16 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 14:08:37 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#include "libft.h"

void			scoreboard(t_filler *filler)
{
	SDL_Event	ev;
	SDL_Texture	*tx;
	SDL_Rect	rc;

	SDL_SetTextureColorMod((tx = get_text(filler, "GAME OVER")), 255, 255, 255);
	rc = get_rect(300, 660, 400, 80);
	SDL_RenderCopy(filler->ren, tx, NULL, &rc);
	SDL_DestroyTexture(tx);
	SDL_RenderPresent(filler->ren);
	while (filler->run)
		SDL_PollEvent(&ev) ? event(ev, filler) : 0;
	SDL_DestroyWindow(filler->win);
}

void			render_score(t_filler *filler)
{
	SDL_Texture		*tx;
	SDL_Rect		rc;
	char			*tmp;

	tmp = ft_itoa(filler->score_o);
	SDL_SetTextureColorMod((tx = get_text(filler, tmp)), 255, 0, 0);
	free(tmp);
	rc = get_rect(40, 150, (int)ft_strlen(tmp) * 15, 30);
	SDL_RenderCopy(filler->ren, tx, NULL, &rc);
	SDL_DestroyTexture(tx);
	tmp = ft_itoa(filler->score_x);
	SDL_SetTextureColorMod((tx = get_text(filler, tmp)), 0, 0, 255);
	free(tmp);
	rc = get_rect(960 - (int)ft_strlen(tmp) * 15, 150,
	(int)ft_strlen(tmp) * 15, 30);
	SDL_RenderCopy(filler->ren, tx, NULL, &rc);
	SDL_DestroyTexture(tx);
	SDL_SetTextureColorMod((tx = get_text(filler, "FILLER")), 255, 255, 255);
	rc = get_rect(390, 50, 220, 75);
	SDL_RenderCopy(filler->ren, tx, NULL, &rc);
	SDL_DestroyTexture(tx);
}
