/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/05 22:59:13 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->win = NULL;
	game->img = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->space = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->line = 0;
}

// void	init_map(t_game *game)
// {

// }