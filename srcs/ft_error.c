/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:25:10 by akram             #+#    #+#             */
/*   Updated: 2023/02/14 00:50:11 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_error(char *str)
{
	while (*str)
		write (1, str++, 1);
	exit (1);
}

void ft_free_map(t_game *game)
{
	int i;
	i = 0;

	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void ft_free_path(t_game *game)
{
	int i;
	i = 0;

	while (game->path[i])
	{
		free(game->path[i]);
		i++;
	}
	free(game->path);
}
void	ft_error_path(t_game *game)
{
	//ft_free_path(game);
	//ft_free_map(game);
	//free(game);
	(void)game;
	printf("invalid path\n");
	exit (EXIT_FAILURE);
}

void	ft_error_path_collect(t_game *game)
{
	//ft_free_path(game);
	//ft_free_map(game);
	//free(game);
	(void)game;
	printf("invalid path collect\n");
	exit (EXIT_FAILURE);
}
