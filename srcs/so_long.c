/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/13 14:56:26 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	int x;
	int y;
	
	fd = open(av[1], O_RDONLY);
	check_arg(ac, av);
	game = ultimate_parsing(fd);

	game.height = count_line(game.map);
	game.width = ft_strlen(game.map[0]);
	printf("\nValeur de hauteur == %d\n", game.height);
	printf("\nValeur de largeur == %d\n", game.width);

	ft_pos_exit(&game, &x, &y);
	if (!ft_path(&game, x, y))
		ft_error_path(&game);
	ft_items(&game);
	if (ft_check_items(&game) == 0)
		ft_error_path_collect(&game);
	//game = window(game);
	printf("collectible vaut == [%d]\n", game.collectible);
}
