/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:42:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/06 19:46:33 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define BACKGROUND "textures/background.png"
# define EARTH "textures/earth.png"
# define ROCK "textures/rock.png"
# define ROCKET "textures/rocket.png" 

typedef struct s_game
{
	mlx_t	*mlx;
	void	*window;
	int	width;
	int	height;
	void	*id;
	//char	**map;
}	t_game;

typedef struct s_image
{
	void	*background;
	void	*earth;
	void	*rock;
	void	*rocket;
	void	*background_tex;
	void	*earth_tex;
	void	*rock_tex;
	void	*rocket_tex;
}	t_image;


t_game	*init_game(void);
t_image	*init_image(void);
void	put_image(t_game *game);

#endif
