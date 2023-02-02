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