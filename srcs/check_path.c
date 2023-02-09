/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 16:15:19 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_error_path(t_game *map)
{
	//ft_free_path(map);
	//ft_free_tab(map);
	//free(map);
	(void)map;
	printf("invalid path\n");
	exit (EXIT_FAILURE);
}

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

void	ft_error_path_collect(t_game *map)
{
	//ft_free_path(map);
	//ft_free_tab(map);
	//free(map);
	(void)map;
	printf("invalid path collect\n");
	exit (EXIT_FAILURE);
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
