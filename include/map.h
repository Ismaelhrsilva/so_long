/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:44:51 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/03 21:25:41 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../lib/libft/gnl/get_next_line.h"

typedef struct s_map
{
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	ncollect;
}	t_map;

void	read_map(char **map);
#endif
