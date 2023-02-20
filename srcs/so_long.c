/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/20 15:46:37 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	end_of_game(t_game *game)
{
	printf("END OF THE GAME\n");
	free_all(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(av[1], O_RDONLY);
	check_arg(ac, av, &game);
	ultimate_parsing(fd, &game);
	ft_check_path(&game, x, y);
	window(&game);
	close(fd);
}
