/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:25:05 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 15:05:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <SDL.h>
# include <SDL_ttf.h>

typedef struct		s_filler
{
	char			*map;

	SDL_Window		*win;
	SDL_Renderer	*ren;

	char			run;
	char			player;
	int				map_x;

	double			dim[2];
	int				score_o;
	int				score_x;

	TTF_Font		*font;
}					t_filler;

char				parse(t_filler *filler);
void				display(t_filler *filler);
void				scoreboard(t_filler *filler);
void				render_score(t_filler *filler);
void				event(SDL_Event ev, t_filler *filler);

void				draw_rect(t_filler *filler, int x, int y);
SDL_Texture			*get_text(t_filler *filler, char *text);
SDL_Rect			get_rect(int x, int y, int w, int h);

#endif
