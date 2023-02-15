/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/15 17:39:00 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	int x;
	int y;
	x = 0;
	y = 0;
	
	fd = open(av[1], O_RDONLY);
	check_arg(ac, av);
	ultimate_parsing(fd, &game);
	ft_check_path(&game,x,y);
	printf("appel main de height == %d\n", game.height);
	window(&game);
	close(fd);
}
