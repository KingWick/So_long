/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 19:12:12 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	init_game(&game);
	check_arg(ac, av, &game);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno), &game);
	ultimate_parsing(fd, &game);
	ft_check_path(&game);
	window(&game);
}
