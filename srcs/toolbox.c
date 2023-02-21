/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 19:51:53 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
	ft_printf("AHAHAHAHA END OF THE GAME\n");
	free_all(game);
	exit(0);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		count += ft_putnbr_u(nb / 10);
		count += ft_putnbr_u(nb % 10);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
