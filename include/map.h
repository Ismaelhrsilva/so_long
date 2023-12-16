/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:44:51 by ishenriq          #+#    #+#             */
/*   Updated: 2023/12/16 19:47:49 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../lib/gnl/get_next_line.h"

typedef struct s_map
{
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	ncollect;
}	t_map;
