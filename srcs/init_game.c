/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 15:27:43 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_game	init_game(t_game game)
{
	game.win = NULL;
	game.img = NULL;
	game.wall = NULL;
	game.floor = NULL;
	game.player = 0;
	game.height = 0;
	game.width = 0;
	game.exit = 0;
	game.collectible = 0;
	game.line = 0;
	return (game);
}

// t_game window(t_game game)
// {
// 	game.mlx = mlx_init(); //initialisation de la bibli mlx renvoi Null si echoue 
// 	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "So long");
// 	return (game);
// }

// t_game texture(t_game game)
// {
// 	int x = 64;
	
// 	game.player = mlx_xpm_file_to_image(game.mlx, "kratos.xpm", &x,&x);
// 	game.wall = mlx_xpm_file_to_image(game.mlx, "./img/wall2.xpm", &x,&x);
// 	game.floor = mlx_xpm_file_to_image(game.mlx, "./img/wall2.xpm", &x,&x);
// 	return (game);
// }

// t_game	dl_texture(t_game game)
// {
// 	int	size;

// 	size = 64;
// 	game.wall = mlx_xpm_file_to_image(game.mlx,
// 			"./textures/wall-64t.xpm", &size, &size);
// 	game.img_player = mlx_xpm_file_to_image(game.mlx,
// 			"./textures/player-64.xpm", &size, &size);
// 	game.img_coin = mlx_xpm_file_to_image(game.mlx,
// 			"./textures/collectible-64.xpm", &size, &size);
// 	game.img_exi = mlx_xpm_file_to_image(game.mlx,
// 			"./textures/exit-64.xpm", &size, &size);
// 	game.floor = mlx_xpm_file_to_image(game.mlx,
// 			"./textures/bottom-64.xpm", &size, &size);
// 	return (game);
// }

// t_game	open_window(t_game game)
// {
// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, game.nb_char * 64,
// 			game.line * 64, "so_long");
// 	game = dl_texture(game);
// 	return (game);
// }