/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:25:10 by akram             #+#    #+#             */
/*   Updated: 2023/02/20 14:37:11 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_error(char *str)
{
	while (*str)
		write (1, str++, 1);
	exit (1);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_free_path(t_game *game)
{
	int	i;

	i = 0;
	while (game->path[i])
	{
		free(game->path[i]);
		i++;
	}
	free(game->path);
}

void	ft_error_path(t_game *game, char *str)
{
	ft_free_path(game);
	ft_free_map(game);
	while (*str)
		write (1, str++, 1);
	exit (1);
}

void	free_all(t_game *game)
{
	ft_free_map(game);
	mlx_destroy_image(game->mlx, game->p);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->f);
	mlx_destroy_image(game->mlx, game->c);
	mlx_destroy_image(game->mlx, game->e);
	mlx_destroy_window(game->mlx, game->win);
}
