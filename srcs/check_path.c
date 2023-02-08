/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/08 13:56:14 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int        validNum(char c)
{
    if (c == '0' || c == 'C' || c == 'E')
        return (1);
	else
	return (0);
}

int        ft_search(char **str, int x, int y, int nbrObject, int exitFound)
{
    if (str[x][y] == 'E')
        exitFound = 1;
    else if (str[x][y] == 'C')
        nbrObject--;
    if (exitFound && nbrObject <= 0)
        return (1);
    str[x][y] = 'x';
    if (validNum(str[x][y + 1])) {
        if (ft_search(str, x, y + 1, nbrObject, exitFound) == 1)
            return (1);
    }
    if (validNum(str[x][y - 1])) {
        if (ft_search(str, x, y - 1, nbrObject, exitFound) == 1)
            return (1);
    }
    if (validNum(str[x + 1][y])) {
        if (ft_search(str, x + 1, y, nbrObject, exitFound) == 1)
            return (1);
    }
    if (validNum(str[x - 1][y])) {
        if (ft_search(str, x - 1, y, nbrObject, exitFound) == 1)
            return (1);
    }
    return (0);
}

int ft_possible(char **str, int x, int y, int nbrObject)
{
	size_t	i;

	i = 0;
    int result = ft_search(str, x, y, nbrObject, 0);
	while (str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
	return (result);
}