/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/15 17:30:37 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_pos_player(t_game *game, int *x, int *y)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		line = game->map[i];
		while (line[j + 1])
		{
			if (line[j] == 'P')
			{
				*x = i;
				*y = j;
			}
		j++;
		}
	i++;
	}
}

void	ft_pos_exit(t_game *game, int *x, int *y)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		line = game->map[i];
		while (line[j + 1])
		{
			if (line[j] == 'E')
			{
				*x = i;
				*y = j;
			}
		j++;
		}
	i++;
	}
}

void	ft_backtacking(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'E'
		&& game->path[i][j + 1] != '1')
	{
		game->path[i][j + 1] = '1';
		ft_backtacking(game, i, j + 1);
	}
	if (game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'E'
		&& game->path[i][j - 1] != '1')
	{
		game->path[i][j - 1] = '1';
		ft_backtacking(game, i, j - 1);
	}
	if (game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E'
		&& game->path[i + 1][j] != '1')
	{
		game->path[i + 1][j] = '1';
		ft_backtacking(game, i + 1, j);
	}
	if (game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E'
		&& game->path[i - 1][j] != '1')
	{
		game->path[i - 1][j] = '1';
		ft_backtacking(game, i - 1, j);
	}
}

int	ft_path(t_game *game, int i, int j)
{
	ft_pos_player(game, &i, &j);
	ft_check_collect(game);
	ft_backtacking(game, i, j);
	ft_pos_exit(game, &i, &j);
	game->path[i][j] = 'E';
	if (game->path[i + 1][j] == '1' || game->path[i - 1][j] == '1'
		|| game->path[i][j + 1] == '1' || game->path[i][j - 1] == '1')
		return (1);
	return (0);
}

void ft_check_path(t_game *game, int x, int y)
{
	game->height = count_line(game->map);
	game->width = ft_strlen(game->map[0]);
	
	ft_pos_exit(game, &x, &y);
	if (ft_path(game, x, y) == 0)
		ft_error_path(game);
	ft_items(game);
	if (ft_check_items(game) == 0)
		ft_error_path_collect(game);
	//ft_free_map(game);
	ft_free_path(game);
}
