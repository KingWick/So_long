/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/08 12:42:31 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game(t_game game)
{
	game.map = NULL;
	game.win = NULL;
	game.img = NULL;
	game.wall = NULL;
	game.space = NULL;
	game.player = 0;
	game.exit = 0;
	game.collectible = 0;
	game.line = 0;
}

// void	init_map(t_game *game)
// {

// }