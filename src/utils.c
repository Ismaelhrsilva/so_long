/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:59:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/06 16:55:03 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return count;
}

