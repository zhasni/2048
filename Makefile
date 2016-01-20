#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaury <bmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 13:32:05 by bmaury             #+#    #+#             #
#    Updated: 2015/03/01 17:27:24 by bmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = game_2048

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/

SRC_NAME =	main.c \
			move.c \
			move_down.c \
			move_up.c \
			move_left.c \
			move_right.c \
			loose.c \
			draw_game_num.c \
			add_check.c \
			initscreen.c \
			add_check2.c

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/

LIB_PATH = ./libft/

LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

COMPILE = echo "\033[36mCompile ...."
COMPILED = echo "\033[32mCompiled Successfully"
CLEAN = echo "\033[36mClean ...."
CLEANED = echo "\033[32mCleaned Successfully"

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILE)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(LIB) -I$(INC_PATH) -o $(NAME) $(OBJ) -lncurses -O3
	@$(COMPILED)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CC) $(CFLAGS) -L$(LIB_PATH) -I$(INC_PATH) -o $@ -c $<

clean:
	@$(CLEAN)
	make -C $(LIB_PATH) clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CLEANED)

fclean: clean
	make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
