/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/09 16:13:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//# include <sys/types.h>
//# include <sys/stat.h>
# include <fcntl.h>

# define MLX_ERROR 1
# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080
# define BUFFER_SIZE 1

typedef struct s_game
{
	char	**map;
	char **path;
	int height;
	int width;
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*floor;
	int		player;
	int		exit;
	int		collectible;
	int		line;
}				t_game;

//------------init_game--and_check--------//
t_game	ultimate_parsing(int fd);
t_game	check_element(char **str, t_game game);
t_game	init_game(t_game game);
void	check_line_map(char **str);
void	check_wall(char **str);
int		check_arg(int ac, char **av);
int		valid_files(const char *s1, const char *s2);
int		count_line(char **str);


//----------------graphic_Part----------------//
t_game	window(t_game game);
t_game 	texture(t_game game);



//------------check_path--------//
void	ft_pos_exit(t_game *map, int *x, int *y);
void	ft_items(t_game *map);
void	ft_error_path_collect(t_game *map);
int		ft_path(t_game *map, int i, int j);
int		ft_check_items(t_game *map);


//--------------Error--------------//
int		ft_error_free(t_game *game);
int		ft_error(char *str);
void	ft_error_path(t_game *map);

//------------Get_split_cat---------//
char	**ft_split(char *str, char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
int		boucle(char **stock, int fd, int ret);
//static char	*ft_strnndup(char *s1, int c);
//static int	ft_counting(char *str, char c);

#endif