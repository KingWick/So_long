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
			if (str[0][x] != '1')
				ft_error("Error\nMap not closed on the top");
			if (str[count - 1][x] != '1')
				ft_error("Error\nMap not closed on the bottom");
			if (str[i][0] != '1' || str[i][ nb_char - 1] != '1')
				ft_error("Error\nMap not surrounded by wall");
			if (str[i][x] != '1' && str[i][x] != '0'&& str[i][x] != 'P' && str[i][x] != 'E'&& str[i][x] != 'C')
				ft_error("charba\n");
			x++;
		}
		i++;
	}
}


void	check_line_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
		{
			ft_error("Error\n the size of the map is not correct");
		}
		i++;
	}
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
	check_wall(game.map);
	//game.line = count_line(game.map);
	//printf("%d", count_line(game.map));
	return (game);
}
