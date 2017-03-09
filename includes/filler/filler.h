/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:50 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 15:17:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_filler
{
	char	*map;
	char	*piece;

	int		map_x;
	int		map_y;

	int		piece_x;
	int		piece_y;

	int		off[2];

	char	player;

	char	pad[7];
}					t_filler;

void				parse(t_filler *filler);
void				piece(t_filler *filler);

void				fill(t_filler *filler);

char				insert(t_filler *filler, int x, int y);

#endif
