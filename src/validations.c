/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:01:11 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/05 19:08:58 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return count;
}

int	count_char_prohibited(t_map *map, char *str)
{
	int	wall;
	int	back;
	int	total_c;
	int	allowed_c;

	total_c = map->ncol;
	wall = count_char(str, '1');
	back = count_char(str, '0');
	allowed_c = count_char(str, 'P') + count_char(str, 'C') + 
		count_char(str, 'E') + wall + back;
	if (total_c != allowed_c)
	{
		ft_printf("Letter prohibited");
		return (1);
	}
	else
		return (0);
}

int	right_number_objects(t_main *main)
{
	if (main->map->ncollect < 1)
	{
		ft_printf("No collectables enought !!!");
		return (1);
	}
	if (main->map->nexit != 1)
	{
		ft_printf("there is not 1 exit !!!");
		return (1);
	}
	if (main->map->nplayer != 1)
	{
		ft_printf("There is not 1 player !!!");
		return (1);
	}
	return (0);
}

int	right_ber(t_main *main)
{
	int	len;
	char	*ber;
	int	fd;
	char	*buffer;

	len = ft_strlen(main->map->path_ber);
	ber = &main->map->path_ber[len - 4];
	fd = open(main->map->path_ber, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_printf("Is was not possible to open the map");
		return (1);
	}
	buffer = malloc(10 * sizeof(char));
	if (buffer == NULL)
		return (1);
	if (read(fd, buffer, 1) <= 0)
	{
		ft_printf("Is not a file");
		return (1);
	}
	if (ft_strncmp(ber, ".ber", 4))
	{
		ft_printf("Is not a .BER file");
		return (1);
	}
	return (0);
}
