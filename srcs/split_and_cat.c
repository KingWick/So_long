/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 19:12:12 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char	*ft_strcat(char *dest, char *src)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 2));
	if (!tmp)
		return (NULL);
	while (dest[i] != '\0')
	{
		tmp[i] = dest[i];
		i++;
	}
	j = 0;
	tmp[i] = '\n';
	i++;
	while (src[j] != '\0')
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	free(dest);
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_strnndup(char *s1, int c)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * ++i);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_counting(char *str, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			nb++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (nb);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		k;
	char	**tab;

	if (!str)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_counting(str, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			tab[k] = ft_strnndup(str + i, c);
			k++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	tab[k] = 0;
	return (tab);
}
