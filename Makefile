SRCS		= 	srcs/so_long.c \
				srcs/ft_error.c \
				srcs/parse_check.c \
				srcs/parse_check2.c \
				srcs/check_path.c \
				srcs/check_path2.c \
				srcs/init_game.c \
				srcs/init_game2.c \
				srcs/toolbox.c \
				srcs/move.c \
				srcs/split_and_cat.c \
			  	srcs/get_next_line.c \
			  	srcs/get_next_line_utils.c \


OBJS 		= ${SRCS:.c=.o}
INCLUDES	= includes/
NAME		= so_long
PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

%.o: %.c ./includes/game.h
			${CC} ${CFLAGS} -I$(INCLUDES) -Imlx -Ibass -c $< -o ${<:.c=.o}
			@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

$(NAME): $(PATH_MLX)/libmlx.a $(OBJS) 
	${CC} -o $(NAME) $(OBJS) $(FLAGS)
			@printf "\n\e[36msuccessfully\e[0m_\e[33m compiled \e[92mis ready !\e[0m\e[?25h\n"

$(PATH_MLX)/libmlx.a:
	make -C $(PATH_MLX)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
