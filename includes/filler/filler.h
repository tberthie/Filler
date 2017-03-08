/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:50 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/08 12:28:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_filler
{
	char	player;
	char	pad[3];

	int		pos_y;

	char	*map;
	char	*piece;

	int		map_x;
	int		piece_x;

	int		off[2];
}					t_filler;

void				parse(t_filler *filler);
char				fits(int x, int y, t_filler *filler);
void				piece(t_filler *filler);

char				locked(t_filler *filler);
void				lock(t_filler *filler, char dir);

#endif
