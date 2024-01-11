/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:42:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/08 20:20:23 by ishenriq         ###   ########.org.br   */
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
# include "so_long.h"
# include "../lib/libft/gnl/get_next_line.h"

# define WIDTH 600 
# define HEIGHT 600
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

typedef struct s_map
{
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	ncollect;
	char	*path_ber;
	char	**build_map;
	int	len_image;
}	t_map;

t_game	*init_game(void);
t_image	*init_image(void);
void	put_image(t_game *game, t_map *map, t_image *image);
t_map	*init_map(void);
void	build_matrix_map(t_map *map);
void	read_map(char **ber, t_map *map);
void	resize_image(t_image *image, t_map *map);

#endif
