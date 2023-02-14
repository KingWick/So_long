/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/14 18:23:39 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game(t_game *game)
{
	game->win = NULL;
	game->img = NULL;
	game->wall = NULL;
	game->p = NULL;
	game->f = NULL;
	game->e = NULL;
	game->c = NULL;
	game->player = 0;
	game->height = 0;
	game->width = 0;
	game->exit = 0;
	game->collectible = 0;
	game->line = 0;
}

void window(t_game *game)
{
	game->mlx = mlx_init(); //initialisation de la bibli mlx renvoi Null si echoue 
	if (game->mlx == NULL)
		ft_error("Error\nInitialization failed");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "So long");
	if (texture(game) == 1)
		ft_error("Error\nloading textures\n");
	mlx_loop(game->mlx);
}

int texture(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	// while (i < ft_strlen(game.map[0]))// i < le nombre de lignes de la map
	// {
	// 	while (j )// j < ft_strlen d'une ligne
	// 	{
	// 		if (game.map[i][j] == '1')
	// 			mlx_put_image_to_window(game->mlx, game->win, game->p, i * 64, j * 64);
	// 			j++;
	// 	}
	// 	i+;
	// }	
	game->p = mlx_xpm_file_to_image(game->mlx, "./img/kratos.xpm", &x, &y);
	if (game->p == NULL || x != 64 || y != 64)
		return (1);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &x, &y);
	if (game->wall == NULL || x != 64 || y != 64)
		return (1);
	game->f = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &x, &y);
	if (game->f == NULL || x != 64 || y != 64)
		return (1);
	game->c = mlx_xpm_file_to_image(game->mlx, "./img/coins.xpm", &x, &y);
	if (game->c == NULL || x != 64 || y != 64)
		return (1);
	game->e = mlx_xpm_file_to_image(game->mlx, "./img/coins.xpm", &x, &y);
	if (game->e == NULL || x != 64 || y != 64)
		return (1);
	return (0);
}
