/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 14:48:44 by akdjebal         ###   ########.fr       */
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
	//game = window(game);
	//printf("collectible vaut == [%d]\n", game.collectible);
}
