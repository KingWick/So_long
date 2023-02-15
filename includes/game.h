/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:43 by akram             #+#    #+#             */
/*   Updated: 2023/02/15 17:41:54 by akdjebal         ###   ########.fr       */
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
	char	**path;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*p;
	void	*f;
	void	*e;
	void	*c;
	int		height;
	int		width;
	int		player;
	int		exit;
	int		collectible;
}				t_game;

//------------init_game--and_check--------//
void	ultimate_parsing(int fd, t_game *game);
void	check_element(char **str, t_game *game);
void	init_game(t_game *game);
void	check_line_map(char **str);
void	check_wall(char **str);
int		check_arg(int ac, char **av);
int		valid_files(const char *s1, const char *s2);
int		count_line(char **str);

//----------------graphic_Part----------------//
void	aff_map(t_game *game);
void	window(t_game *game);
void	display_wall(t_game *game);
void	display_player(t_game *game);
void	display_exit(t_game *game);
void	display_floor(t_game *game);
void	display_collectible(t_game *game);
int		texture(t_game *game);


//------------check_path--------//
void 	ft_check_path(t_game *game, int x, int y);
void	ft_backtacking(t_game *game, int i, int j);
void	ft_pos_player(t_game *game, int *x, int *y);
void	ft_pos_exit(t_game *game, int *x, int *y);
void	ft_check_collect(t_game *game);
void	ft_items(t_game *game);
void	ft_null_map(char *path, t_game *game);
int		ft_path(t_game *game, int i, int j);
int		ft_check_items(t_game *game);

//--------------Error--------------//
void	ft_error_path_collect(t_game *game);
int		ft_error(char *str);
void	ft_error_path(t_game *game);
void 	ft_free_map(t_game *game);
void 	ft_free_path(t_game *game);


//------------Utils_libft---------//
char	**ft_split(char *str, char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);

#endif
