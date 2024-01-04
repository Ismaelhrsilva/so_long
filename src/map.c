/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/03 22:02:37 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

void	read_map(char **map)
{
	int fd;
	char	*gnl;

	fd = open(*map, O_RDONLY);
	gnl = NULL;
	if (fd < 0)
		return ;
	while(gnl == get_next_line(fd))
		ft_printf("%s", gnl);
}
