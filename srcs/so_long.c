/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:01:13 by akram             #+#    #+#             */
/*   Updated: 2023/02/05 23:01:16 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <string.h>

int main(int ac, char **av)
{
	t_game game;
	int fd;
	fd = open(av[1], O_RDONLY);
	check_arg(ac,av);
	game = ultimate_parsing(fd);
	printf("%p", game.mlx);
}
