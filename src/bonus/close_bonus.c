/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:53:40 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/11 14:18:31 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"
void	ft_close(t_main *main)
{
	int				i;
	static t_list	*aux;

	i = 0;
	aux = main->list;
	if (main->map->space)
	{
		while (i < main->map->nrow)
			free(main->map->space[i++]);
		free(main->map->space);
	}
	if (main->list)
	{
		while (aux)
		{
			free(aux->content);
			aux = aux->next;
			free(main->list);
			main->list = aux;
		}
	}
}
