/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:50 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 17:00:59 by tberthie         ###   ########.fr       */
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

	char	target[8];
	int		dir;

	char	pad[3];

	char	player;
}					t_filler;

void				parse(t_filler *filler);
void				piece(t_filler *filler);

void				fill(t_filler *filler);
void				check_targets(t_filler *filler);

#endif
