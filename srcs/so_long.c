/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/08 12:42:38 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	fd = open(av[1], O_RDONLY);
	check_arg(ac, av);
	game = ultimate_parsing(fd);
	printf("collectible vaut == [%d]\n", game.collectible);
	printf("exit vaut == [%d]\n", game.exit);
	printf("player vaut == [%d]\n", game.player);
	printf("line vaut == [%d]\n", game.line);
	//printf("collectible vaut == [%d]\n", game.collectible);
}
