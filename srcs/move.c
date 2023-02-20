/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/20 21:36:20 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

// int	up(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	ft_pos_player(game, &x, &y);
// 	if (game->map[x - 1][y] == '1' ||
// 			(game->map[x - 1][y] == 'E' && game->collectible != 0))
// 		return (0);
// 	if (game->map[x - 1][y] == 'C')
// 		game->collectible--;
// 	if (game->map[x - 1][y] == 'E' && game->collectible == 0)
// 		end_of_game(game);
// 	game->map[x - 1][y] = 'P';
// 	game->map[x][y] = '0';
// 	game->count++;
// 	printf("COUNT === %d\n", game->count);
// 	return (0);
// }

// int	right(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	ft_pos_player(game, &x, &y);
// 	if (game->map[x][y + 1] == '1' ||
// 			(game->map[x][y + 1] == 'E' && game->collectible != 0))
// 		return (0);
// 	if (game->map[x][y + 1] == 'C')
// 		game->collectible--;
// 	if (game->map[x][y + 1] == 'E' && game->collectible == 0)
// 		end_of_game(game);
// 	game->map[x][y + 1] = 'P';
// 	game->map[x][y] = '0';
// 	game->count++;
// 	printf("COUNT === %d\n", game->count);
// 	return (0);
// }

// int	left(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	ft_pos_player(game, &x, &y);
// 	if (game->map[x][y - 1] == '1' ||
// 			(game->map[x][y - 1] == 'E' && game->collectible != 0))
// 		return (0);
// 	if (game->map[x][y - 1] == 'C')
// 		game->collectible--;
// 	if (game->map[x][y - 1] == 'E' && game->collectible == 0)
// 		end_of_game(game);
// 	game->map[x][y - 1] = 'P';
// 	game->map[x][y] = '0';
// 	game->count++;
// 	printf("COUNT === %d\n", game->count);
// 	return (0);
// }

// int	down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	ft_pos_player(game, &x, &y);
// 	if (game->map[x + 1][y] == '1' ||
// 		(game->map[x + 1][y] == 'E' && game->collectible != 0))
// 		return (0);
// 	if (game->map[x + 1][y] == 'C')
// 		game->collectible--;
// 	if (game->map[x + 1][y] == 'E' && game->collectible == 0)
// 		end_of_game(game);
// 	game->map[x + 1][y] = 'P';
// 	game->map[x][y] = '0';
// 	game->count++;
// 	printf("COUNT === %d\n", game->count);
// 	return (0);
// }
