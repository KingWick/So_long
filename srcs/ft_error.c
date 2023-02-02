#include "../includes/game.h"

int	ft_error(char *str)
{
	while(*str)
		write (1,str++,1);
	exit (1);
}

int	ft_error_free(t_game *game)
{
	if (game->map)
		free(game->map);
	write(1,"Error\n",6);
	return (0);
}