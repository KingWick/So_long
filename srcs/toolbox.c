/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 16:57:00 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

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
	if (close(fd) == -1)
		(free(map), ft_error(strerror(errno), game));
	line_break(map);
	game->map = ft_split(map, '\n');
	free(map);
	check_line_map(game);
	check_map(game);
	check_element(game);
}

int	end_of_game(t_game *game)
{
	printf("END OF THE GAME\n");
	free_all(game);
	exit(0);
}

