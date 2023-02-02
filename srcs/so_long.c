#include "../includes/game.h"
#include <string.h>

int main(int ac, char **av)
{
	t_game game;
	int fd;
	fd = open(av[1], O_RDONLY);
	check_arg(ac,av);
	game = ultimate_parsing(fd);
}

// int main(int ac,char **av)
// {
//     check_arg(ac,av);
//     int fd = open(av[ac-1], O_RDONLY);
//     int i = 0;
// 		int k = 0; 
//     char *line = NULL;
// 		char *last_line = NULL;
//     int first_line = 0;
//     while (get_next_line(fd, &line) == 1)
//     {
//         if (first_line == 0)
//         {
//             while (line[i])
//             { 
//                 if (line[i] != '1')
//                     ft_error("Map invalid");
//                 i++;
// 			}
//      }
// 		first_line++;
// 		last_line = line;
//     }
// 	while (last_line[k])
// 	{
// 		if (last_line[k] != '1')
// 			ft_error("Map invalid");
// 		k++;
// 	}
// 	lecture(line);
//     close(fd);
// }
