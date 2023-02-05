/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:25:10 by akram             #+#    #+#             */
/*   Updated: 2023/02/05 22:59:09 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_error(char *str)
{
	while(*str)
		write (1,str++,1);
	exit (1);
}

int	ft_error_free(t_game *game)
{
	if (game->map)
		free(game->map);
	write(1,"Error\n",6);
	return (0);
}