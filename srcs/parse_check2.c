/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:54:41 by akram             #+#    #+#             */
/*   Updated: 2023/02/05 22:57:07 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int count_line(char **str)
{
	int i;
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

int check_arg(int ac, char **av)
{
	int fd;
	if (ac != 2)
		ft_error("invalid number of arguments\n");
	if (valid_files(av[1], ".ber") == 1) //av{0} etant lexec av[1] etant le .ber ou autre lresulat dvalid file sfera tjr par la soustraction de -4 (.ber)
		ft_error("fake file extension\n");
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		ft_error("Invalid files\n");
		close(fd);
	}
	close(fd);
	return (0);
}