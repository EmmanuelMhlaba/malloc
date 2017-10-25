# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/16 17:42:26 by emmmhla           #+#    #+#              #
#    Updated: 2017/06/18 12:53:00 by emmmhla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -Wall -Werror -Wextra -fPIC -c -o
LDFLAGS = -shared

HEADER_FOLDER = includes
HEADER = ft_malloc.h

SRC_FOLDER = srcs

OBJ_FOLDER = objs
_OBJ = \
	   allocate_large.o allocate_medium.o allocate_new_block.o \
	   allocate_new_zone.o allocate_small.o allocate_tiny.o divide_zone.o \
	   free_chains.o ft_free.o ft_malloc.o ft_realloc.o get_actual_zone_size.o \
	   get_aligned_size.o get_free_block.o map_block.o print_mem_chain.o \
	   show_alloc_mem.o ft_atoa.o ft_printf_fd.o get_format.o
OBJ = $(patsubst %.o, $(OBJ_FOLDER)/%.o, $(_OBJ))

_NAME = libft_malloc.so
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$(HOSTTYPE).so

LIBFT = libft/libft.a

all: $(NAME) $(_NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ) $(HEADER_FOLDER)/$(HEADER) $(LIBFT)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) -L libft -lft -lpthread

$(_NAME): $(NAME)
	@ln -sf $(NAME) $(_NAME)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c $(HEADER_FOLDER)/$(HEADER)
	@$(CC) $(CCFLAGS) $@ $< -I $(HEADER_FOLDER) -I libft/includes

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ_FOLDER)

fclean: clean
	@rm -f $(_NAME) $(NAME)

re: fclean all

norme:
	@$(foreach SRC_FILE, $(patsubst %.o, $(SRC_FOLDER)/%.c, $(_OBJ)), norminette $(SRC_FILE);)
	@norminette $(HEADER_FOLDER)

.PHONY: clean fclean all re norme
