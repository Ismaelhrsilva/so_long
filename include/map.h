/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:44:51 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/05 20:28:44 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../lib/libft/gnl/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_map
{
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	ncollect;
	char	*path_ber;
	char	**build_map;
}	t_map;

t_map	*init_map(void);
void	build_matrix_map(t_map *map);
void	read_map(char **ber, t_map *map);
#endif

