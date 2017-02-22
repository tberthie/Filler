/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:11:50 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/22 17:12:26 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_filler
{
	char	player;
	char	padding[7];

	char	*map;
	char	*piece;

	int		map_x;
	int		piece_x;

	int		off_x;
	int		off_y;
}					t_filler;

void				parse(t_filler *filler);
void				insert(t_filler *filler);
void				piece(t_filler *filler);

#endif
