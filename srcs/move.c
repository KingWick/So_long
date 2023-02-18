/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/18 19:10:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	right(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
	{
		game->width = 0;
		while (game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'P')
			{
				if (game->map[game->height][game->width + 1] == '1')
					return (0);
				if (game->map[game->height][game->width + 1] == 'E' &&
						game->collectible != 0)
					return (0);
				moove_right(game);
				return (0);
			}
			game->width++;
		}
		game->height++;
	}
	return (0);
}

int left(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
	{
		game->width = 0;
		while (game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'P')
			{
				if (game->map[game->height][game->width - 1] == '1')
					return (0);
				if (game->map[game->height][game->width - 1] == 'E' &&
						game->collectible != 0)
					return (0);
				moove_left(game);
				return (0);
			}
			game->width++;
		}
		game->height++;
	}
	return (0);
}

int	moove_left(t_game *game)
{
	if (game->map[game->height][game->width - 1] == 'C')
		game->collectible--;
	if (game->map[game->height][game->width - 1] == 'E'
			&& game->collectible == 0)
	{
		game->nb_mouv++;
		printf("nb_move === %d\n", game->nb_mouv);
		printf("END OF THE GAME");
		// free_all(game);
		exit(0);
	}
	game->map[game->height][game->width - 1] = 'P';
	game->map[game->height][game->width] = '0';
	aff_map(game);
	game->nb_mouv++;
	printf("nb_move === %d\n", game->nb_mouv);
	return (0);
}

int	moove_right(t_game *game)
{
	if (game->map[game->height][game->width + 1] == 'C')
		game->collectible--;
	if (game->map[game->height][game->width + 1] == 'E'
			&& game->collectible == 0)
	{
		game->nb_mouv++;
		printf("nb_move === %d\n", game->nb_mouv);
		printf("END OF THE GAME");
		// free_all(game);
		exit(0);
	}
	game->map[game->height][game->width + 1] = 'P';
	game->map[game->height][game->width] = '0';
	aff_map(game);
	game->nb_mouv++;
	printf("nb_move === %d\n", game->nb_mouv);
	return (0);
}