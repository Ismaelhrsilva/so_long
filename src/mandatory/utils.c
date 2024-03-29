/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:59:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/11 09:26:19 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/so_long.h"

int	ft_strlenspace(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str && str[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

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
	return (count);
}

int	count_char_prohibited(t_map *map, char *str)
{
	int	wall;
	int	back;
	int	exit;
	int	total_c;
	int	allow_c;

	total_c = map->ncol;
	wall = count_char(str, '1');
	back = count_char(str, '0');
	exit = count_char(str, 'E');
	allow_c = count_char(str, 'P') + count_char(str, 'C') + exit + wall + back;
	if (total_c != allow_c)
	{
		ft_putstr_fd("Error\nLetter prohibited", 2);
		return (1);
	}
	else
		return (0);
}
