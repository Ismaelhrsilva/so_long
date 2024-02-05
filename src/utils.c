/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:59:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/05 20:12:32 by ishenriq         ###   ########.org.br   */
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
