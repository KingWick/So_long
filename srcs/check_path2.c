/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 17:08:03 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_null_map(char *path, t_game *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		path[i] = '0';
		i++;
	}
	path[i] = '\0';
}

void	ft_check_collect(t_game *map)
{
	int	i;

	i = 0;
	map -> path = (char **) malloc(sizeof(char *) * (map -> height + 1));
	map -> path[map->height] = NULL;
	while (i < map->height)
	{
		map->path[i] = (char *) malloc(sizeof(char) * (map->width + 1));
		ft_null_map(map->path[i], map);
		i++;
	}
	map->path[i] = NULL;
}

void	ft_items(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C' && map->path[i][j] == '0')
				map->path[i][j] = 'C';
			j++;
		}
		i++;
	}
}

int	ft_check_items(t_game *map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->path[i][j] == 'C')
				count_c ++;
			j++;
		}
		i++;
	}
	if (count_c == 0)
		return (1);
	return (0);
}
