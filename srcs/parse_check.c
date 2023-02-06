/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/06 16:50:26 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <string.h>

void	check_line_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
			ft_error("Error\nThe size of the map is not correct");
		i++;
	}
}

void	check_wall(char **str)
{
	int	x;
	int	i;
	int	count;
	int	nb_char;

	x = 0;
	i = 0;
	count = count_line(str);
	nb_char = ft_strlen(str[0]);
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[count - 1][x] != '1')
				ft_error("Error\nMap not closed on the bottom");
			if (str[i][0] != '1' || str[i][ nb_char - 1] != '1')
				ft_error("Error\nMap not surrounded by wall");
			x++;
		}
		i++;
	}
}

void	check_map(char **str)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[0][x] != '1')
				ft_error("Error\nMap not closed on the top");
			if (str[i][x] != '1' && str[i][x] != '0' && str[i][x] != 'P'
				&& str[i][x] != 'E' && str[i][x] != 'C')
			{
				ft_error("Error\nUnknown character");
			}
			x++;
		}
		i++;
	}
	check_wall(str);
}

void	check_element(char **str)
{
	t_game	game;
	int		i;
	int		x;

	x = 0;
	i = 0;
	//init_game(game);
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[i][x] == 'P')
				game.player++;
			else if (str[i][x] == 'E')
				game.exit++;
			else if (str[i][x] == 'C')
				game.collectible = 2;
			x++;
		}
		i++;
	}
	printf("\ncollectible vaut == [%d]\n", game.collectible);
	// if (game.player || game.exit > 2)
	// 	ft_error("errrrrrror\n");
	printf("player vaut == [%d]\nExit vaut == [%d]", game.player, game.exit);
}

t_game	ultimate_parsing(int fd)
{
	t_game	game;
	char	*line;
	char	*map;

	get_next_line(fd, &map);
	while (get_next_line(fd, &line) == 1)
	{
		map = ft_strcat(map, line);
		free(line);
	}
	map = ft_strcat(map, line);
	free(line);
	game.map = ft_split(map, '\n');
	free(map);
	check_line_map(game.map);
	check_map(game.map);
	check_element(game.map);
	return (game);
}
