/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:25:10 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 16:52:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_error(char *str)
{
	while (*str)
		write (1, str++, 1);
	exit (1);
}

int	ft_error_free(t_game *game)
{
	if (game->map)
		free(game->map);
	write (1, "Error\n", 6);
	return (0);
}

void	ft_error_path(t_game *map)
{
	//ft_free_path(map);
	//ft_free_tab(map);
	//free(map);
	(void)map;
	printf("invalid path\n");
	exit (EXIT_FAILURE);
}

void	ft_error_path_collect(t_game *map)
{
	//ft_free_path(map);
	//ft_free_tab(map);
	//free(map);
	(void)map;
	printf("invalid path collect\n");
	exit (EXIT_FAILURE);
}
