/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:25:05 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/08 17:15:49 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <SDL.h>
# include <SDL_ttf.h>

typedef struct		s_filler
{
	SDL_Window		*win;
	SDL_Renderer	*ren;

	char			run;
	char			player;
	char			pad[2];

	int				pos_y;

	char			*map;
	char			*piece;

	int				map_x;
	int				piece_x;

	int				off[2];

	double			dim[2];
	int				score_o;
	int				score_x;

	TTF_Font		*font;
}					t_filler;

char				parse(t_filler *filler);
void				piece(t_filler *filler);
void				display(t_filler *filler);
void				draw_rect(t_filler *filler, int x, int y);
SDL_Texture			*get_text(t_filler *filler, char *text);
void				scoreboard(t_filler *filler);
void				event(SDL_Event ev, t_filler *filler);
SDL_Rect			get_rect(int x, int y, int w, int h);
void				render_score(t_filler *filler);

#endif
