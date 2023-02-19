/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/19 19:43:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game(t_game *game)
{
	game->win = NULL;
	game->mlx = NULL;
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
	game->nb_mouv = 0;
}

void window(t_game *game)
{
	game->mlx = mlx_init(); //initialisation de la bibli mlx renvoi Null si echoue 
	if (game->mlx == NULL)
		ft_error("Error\nInitialization failed");//a cet endroit du code on a malloc game->map, game->path, mlx
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "So long");
	if (texture(game) == 1)
		ft_error("Error\nloading textures\n");
	
	aff_map(game);
	mlx_key_hook(game->win, keys, game);
	mlx_loop(game->mlx);
}

int texture(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
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
	game->e = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &x, &y);
	if (game->e == NULL || x != 64 || y != 64)
		return (1);
	return (0);
}

void	aff_map(t_game *game)
{
	display_wall(game);
	display_floor(game);
	display_player(game);
	display_collectible(game);
	display_exit(game);
}

int keys(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		ft_free_map(game);
		exit(1);
	}
	if (keycode == RIGHT)
		right(game);
	if (keycode == LEFT)
		left(game);
	if (keycode == UP)
		up(game);
	if (keycode == DOWN)
		down(game);
	aff_map(game);
	return (0);
}
