/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/05 23:22:09 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_line_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
		{
			ft_error("Error\nThe size of the map is not correct");
		}
		printf("i = [%d]\n",i);
		i++;
	}
}

void	check_wall(char **str)
{
	int	x;
	int i;

	x = 0;
	i = 0;
	int count;
	count = count_line(str);
	int nb_char;
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
	int x;
	int i;
	
	x = 0;
	i = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[0][x] != '1')
				ft_error("Error\nMap not closed on the top");
			if (str[i][x] != '1' && str[i][x] != '0'&& str[i][x] != 'P' && str[i][x] != 'E'&& str[i][x] != 'C')
				ft_error("Error\nUnknown character");
			x++;
		}
		i++;
	}
	check_wall(str);
}

t_game ultimate_parsing(int fd)
{
	t_game game;
    char *line;
	char *map;
	
	get_next_line(fd, &map);
    while (get_next_line(fd, &line) == 1)
    {
		map = ft_strcat(map,line);
		free(line);
    }
	map = ft_strcat(map, line);
	free(line);
	game.map = ft_split(map, '\n');
	free(map);
	check_line_map(game.map);
	check_map(game.map);
	return (game);
}
