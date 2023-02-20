/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:54:41 by akram             #+#    #+#             */
/*   Updated: 2023/02/20 13:23:37 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	count_line(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valid_files(const char *s1, const char *s2)
{
	int	i;
	int	start;

	i = 0;
	start = ft_strlen(s1) - ft_strlen(s2);
	while (s1[start + i])
	{
		if (s1[start + i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_error("invalid number of arguments\n");
	if (valid_files(av[1], ".ber") == 1)
		ft_error("fake file extension\n");
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		ft_error("Invalid files\n");
		close(fd);
	}
	if (fd > 0)
		close(fd);
	return (0);
}
