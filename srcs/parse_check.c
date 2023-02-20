/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 00:37:05 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void line_break(char *str)
{
	int i;
	i = 0;
    while (str[i])
    {
        if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n'))
        {
            ft_putstr("Error\nNique ta gross reums\n");
            free(str);
            exit(1);
        }   
        i++;
    }
}

void	check_line_map(char **str,t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
		{
			ft_error("Error\nThe size of the map is not correct\n", game);
		}
		i++;
	}
}

void	check_wall(char **str, t_game *game)
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
				ft_error("Error\nMap not closed on the bottom\n", game);
			if (str[i][0] != '1' || str[i][nb_char - 1] != '1')
				ft_error("Error\nMap not surrounded by wall\n", game);
			x++;
		}
		i++;
	}
}

void	check_map(char **str, t_game *game)
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
				ft_error("Error\nMap not closed on the top\n", game);
			if (str[i][x] != '1' && str[i][x] != '0' && str[i][x] != 'P'
				&& str[i][x] != 'E' && str[i][x] != 'C')
			{
				ft_error("Error\nUnknown character\n", game);
			}
			x++;
		}
		i++;
	}
	check_wall(str,game);
}

void	check_element(char **str, t_game *game)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	init_game(game);
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[i][x] == 'P')
				game->player++;
			else if (str[i][x] == 'E')
				game->exit++;
			else if (str[i][x] == 'C')
				game->collectible++;
			x++;
		}
		i++;
	}
	if (game->exit != 1 || game->player != 1 || game->collectible == 0)
		ft_error("Error\nMissing elements or extra elements\n", game);
}

void	ultimate_parsing(int fd, t_game	*game)
{
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
	game->map = ft_split(map, '\n');
	line_break(map);
	free(map);
	check_line_map(game->map, game);
	check_map(game->map, game);
	check_element(game->map, game);
}