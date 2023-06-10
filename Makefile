# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/06/10 10:10:30 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

CFLAGS_OBJ = -Wall -Wextra -Werror -c -g

RM = rm -f

C_FILES =	main.c \
			parse.c \
			parse_utils.c \
			parse_utils2.c \
			parse_texture.c \
			parse_map.c \
			error.c \
			free.c

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
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) $(MLBX)

clean :
		make clean -C libft
		make clean -C mlx42
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME) $(SLB) libft.a libmlx.a .mandatory .bonus

re : fclean all

.PHONY : all fclean clean re