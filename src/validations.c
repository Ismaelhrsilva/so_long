/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:01:11 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/04 18:39:27 by ishenriq         ###   ########.org.br   */
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

	len = ft_strlen(main->map->path_ber);
	ber = &main->map->path_ber[len - 4];
	//ft_printf("%s\n", ft_strnstr(ber, ".ber", 4));
	if (ft_strncmp(ber, ".ber", 4))
	{
		ft_printf("Is not a .BER file");
		return (1);
	}
	return (0);
}
