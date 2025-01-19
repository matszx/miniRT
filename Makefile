# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:35:04 by mcygan            #+#    #+#              #
#    Updated: 2025/01/19 18:22:04 by mcygan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	miniRT
CC 				=	cc
CFLAGS 			=	-Wall -Wextra -Werror -fsanitize=address #-O3 -ffast-math
INC				=	-I/usr/include -Imlx
LIB				=	-Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext -lm

SRC_FILES 		=	main.c \
					camera.c \
					vector_math.c \
					utils.c

SRC_DIR			=	src/
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR			=	obj/
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

all				:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(NAME)			:	$(OBJ)
					@make -C mlx
					$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIB)

clean			:
					@make clean -C mlx
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
