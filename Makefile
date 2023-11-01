# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/11/01 20:34:46 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c -g

RM = rm -f

C_FILES =	main.c \
			parse.c \
			parse_utils.c \
			parse_file.c \
			parse_texture.c parse_texture_utils.c \
			parse_map.c \
			error.c \
			free.c \
			init.c \
			init_utils.c \
			ft_init_image.c \
			init_player.c \
			event.c \
			draw.c draw_utils.c \
			raycasting.c raycasting_utils.c raycasting_utils2.c \
			move.c \
			rotate.c \
			garbe.c

SRC = $(addprefix src/, $(C_FILES))

OBJ = $(SRC:.c=.o)

INC = -I includes/

LIB = -L. -lft

MLBX = libmlx.a -Iinclude -ldl -lglfw -pthread -lm -lmlx -lXext -lX11

NAME = cub3D

all : $(NAME)

libft.a :
			make bonus -C libft
			
libmlx.a :
			make -C mlx42

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

$(NAME) : libft.a libmlx.a $(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LIB) $(MLBX)

clean :
		make clean -C libft
		make clean -C mlx42
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME) $(SLB) libft.a libmlx.a .mandatory .bonus

re : fclean all

prog : all clean
		clear

.PHONY : all fclean clean re