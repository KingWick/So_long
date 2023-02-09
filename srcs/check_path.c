/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 16:56:33 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_pos_player(t_game *map, int *x, int *y)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		line = map->map[i];
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

void	ft_pos_exit(t_game *map, int *x, int *y)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		line = map->map[i];
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

void	ft_backtacking(t_game *map, int i, int j)
{
	if (map->map[i][j + 1] != '1' && map->map[i][j + 1] != 'E'
		&& map->path[i][j + 1] != '1')
	{
		map->path[i][j + 1] = '1';
		ft_backtacking(map, i, j + 1);
	}
	if (map->map[i][j - 1] != '1' && map->map[i][j - 1] != 'E'
		&& map->path[i][j - 1] != '1')
	{
		map->path[i][j - 1] = '1';
		ft_backtacking(map, i, j - 1);
	}
	if (map->map[i + 1][j] != '1' && map->map[i + 1][j] != 'E'
		&& map->path[i + 1][j] != '1')
	{
		map->path[i + 1][j] = '1';
		ft_backtacking(map, i + 1, j);
	}
	if (map->map[i - 1][j] != '1' && map->map[i - 1][j] != 'E'
		&& map->path[i - 1][j] != '1')
	{
		map->path[i - 1][j] = '1';
		ft_backtacking(map, i - 1, j);
	}
}

int	ft_path(t_game *map, int i, int j)
{
	ft_pos_player(map, &i, &j);
	ft_check_collect(map);
	ft_backtacking(map, i, j);
	ft_pos_exit(map, &i, &j);
	map->path[i][j] = 'E';
	if (map->path[i + 1][j] == '1' || map->path[i - 1][j] == '1'
		|| map->path[i][j + 1] == '1' || map->path[i][j - 1] == '1')
		return (1);
	return (0);
}
