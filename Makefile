# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:51:30 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/23 10:25:11 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For mem : @ before a commande hide the echo of the command

CC =		clang
FLAGS =		-Wall -Werror -Wextra -O2
NAME =		fractol
INCLS =		-I./includes -I./libft/includes 
LIBFT = 	-L./libft -lft \
			-L./libmlx -lmlx -framework OpenGL -framework AppKit
SRCS_DIR =	srcs
OBJS_DIR =	objs

LIBS =	libft/libft.a \
		libmlx/libmlx.a

LIST =	main \
		error/error \
		fract_data/mandelbrot \
		fract_data/julia \
		fract_data/douady_rabbit \
		fract_data/burning_ship \
		mlx/new_image \
		mlx/mlx_init \
		hooks/key_hook \
		hooks/key_hook_bis \
		hooks/zoom_hook \
		hooks/hover_hook \
		draw/draw



SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(LIST)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIST)))

all: $(NAME)

libft/libft.a:
	make -C libft

libmlx/libmlx.a:
	make -C libmlx

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
