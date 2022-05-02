# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 05:17:18 by orfreoua          #+#    #+#              #
#    Updated: 2021/10/26 11:41:48 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/draw_map.c \
		./srcs/draw.c \
		./srcs/f_libft.c \
		./srcs/free.c \
		./srcs/ft_itoa.c \
		./srcs/game.c \
		./srcs/load_img.c \
		./srcs/read.c \
		./srcs/utils.c \
		./srcs/load_map.c \
		./srcs/bonus.c \

MAIN =	./srcs/main.c \

MAIN_BONUS = ./srcs/main_bonus.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${MAIN_BONUS:.c=.o}
OBJS_M		= ${MAIN:.c=.o}
PATH_MLX	= mlx
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror  -g3
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

# valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long assets/maps/map.ber


all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${OBJS_M}
			make -C mlx
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} $(FLAGS)

bonus:		${OBJS} ${OBJS_B}
			make -C mlx
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_B} $(FLAGS)

$(NAME_BONUS): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGSB)


clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME} ${OBJS_B}

re: 		fclean all
