/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/15 14:24:23 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	display_wall(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
	{
		game->width = 0;
		while (game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					game->width * 64, game->height * 64);
			game->width++;
		}
		//printf("s == %s\n", game->map[game->height]);
		game->height++;
	}
}

void	display_floor(t_game *game)
{
	game->height = 0;
	while(game->map[game->height])
	{
		game->width = 0;
		while(game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->f,
					game->width * 64, game->height * 64);
			game->width++;
		}
		game->height++;
	}
}


void	display_player(t_game *game)
{
	game->height = 0;
	while(game->map[game->height])
	{
		game->width = 0;
		while(game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->p,
					game->width * 64, game->height * 64);
			game->width++;
		}
		game->height++;
	}
}


void	display_exit(t_game *game)
{
	game->height = 0;
	while(game->map[game->height])
	{
		game->width = 0;
		while(game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->e,
					game->width * 64, game->height * 64);
			game->width++;
		}
		game->height++;
	}
}

void	display_collectible(t_game *game)
{
	game->height = 0;
	while(game->map[game->height])
	{
		game->width = 0;
		while(game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c,
					game->width * 64, game->height * 64);
			game->width++;
		}
		game->height++;
	}
}