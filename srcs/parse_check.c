/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 19:18:12 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	line_break(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n' || (str[i] == '\n'
				&& str[i + 1] && str[i + 1] == '\n'))
		{
			write(1, "Error\nMap invalid\n", 18);
			free(str);
			exit(1);
		}
		i++;
	}
}

void	check_line_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			ft_error("Error\nThe size of the map is not correct\n", game);
		i++;
	}
}

void	check_wall(t_game *game)
{
	int	x;
	int	i;
	int	count;
	int	nb_char;

	x = 0;
	i = 0;
	count = count_line(game->map);
	nb_char = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{		
			if (game->map[count - 1][x] != '1')
				ft_error("Error\nMap not closed on the bottom\n", game);
			if (game->map[i][0] != '1' || game->map[i][nb_char - 1] != '1')
				ft_error("Error\nMap not surrounded by wall\n", game);
			x++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[0][x] != '1')
				ft_error("Error\nMap not closed on the top\n", game);
			if (game->map[i][x] != '1' && game->map[i][x] != '0'
					&& game->map[i][x] != 'P'
				&& game->map[i][x] != 'E' && game->map[i][x] != 'C')
			{
				ft_error("Error\nUnknown character\n", game);
			}
			x++;
		}
		i++;
	}
	check_wall(game);
}

void	check_element(t_game *game)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'P')
				game->player++;
			else if (game->map[i][x] == 'E')
				game->exit++;
			else if (game->map[i][x] == 'C')
				game->collectible++;
			x++;
		}
		i++;
	}
	if (game->exit != 1 || game->player != 1 || game->collectible == 0)
		ft_error("Error\nMissing elements or extra elements\n", game);
}
