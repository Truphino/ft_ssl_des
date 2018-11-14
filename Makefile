# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 14:32:25 by dgaitsgo          #+#    #+#              #
#    Updated: 2018/10/19 12:28:31 by trecomps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include

SRC_NAME_FILES =\
main.c\
md5.c\
padding.c\
bitswap.c\
md5_fg_values.c\
h_values_hexstr.c\
hash_tools.c\
sha_helpers.c\
sha256.c\
hash_file.c\
parse_cli.c\
errors.c\
helpers.c\
commands.c\
flag_warpper.c\
launcher.c\
base64.c\

SRC_FILES = $(addprefix $(SRC_DIR)/,$(SRC_NAME_FILES))

OBJ_NAME_FILES = $(SRC_NAME_FILES:.c=.o)

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME_FILES))

INC_FILES = \
./include/externals_headers.h\
./include/ft_ssl_md5.h\
./include/libft.h\
./include/bitswap.h\
./include/get_next_line.h\
./include/hash_tools.h\
./include/sha_helpers.h\

LIB_DIR = ./lib/libft

FLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_FILES)
	gcc -g $(FLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
