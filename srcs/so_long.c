/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 16:54:07 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	init_game(&game);
	check_arg(ac, av, &game);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno), &game);
	ultimate_parsing(fd, &game);
	ft_check_path(&game, x, y);
	window(&game);
//	close(fd);
}
