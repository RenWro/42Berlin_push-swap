# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 13:24:25 by rwrobles          #+#    #+#              #
#    Updated: 2025/03/27 12:48:17 by rwrobles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= push_swap
BONUS		= checker

# Colors for feedback
GREEN		= \033[0;32m
MAGENTA		= \033[0;35m
BLUE		= \033[0;34m
DEFAULT 	= \033[0:0m
GREY		= \033[0;90m
RED			= \033[0;31m
RESET		= \033[0m

# Compiler and flags
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
REMOVE 		= rm -rf

# Directories
SRC_DIR		= src/push_swap
INCLUDE_DIR	= include
BUILD_DIR	= build

# Libft
LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I$(LIBFT_DIR)
LIBFT_MAKE	= make -C $(LIBFT_DIR)

# Source files
NAME_SRC_FILES = algorithm.c		\
				conditional.c       \
				main.c		    	\
				list_ops.C			\
				push.c		    	\
				rev_rotate.c    	\
				rotate.c	     	\
				stack_rule_by_size.c\
				stacking_a.c	    \
				stacking_b.c	    \
				stacks_utils.c      \
				swap.c				\
				validations.c		\
				utils.c

# Object paths
NAME_SRC = $(addprefix $(SRC_DIR)/, $(NAME_SRC_FILES))
NAME_OBJS = $(NAME_SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Includes
NAME_INCLUDES = -I$(INCLUDE_DIR)/push_swap $(LIBFT_INC)

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(LIBFT_MAKE)
	@echo "$(GREEN)Libft compiled!$(RESET)"

$(NAME): $(BUILD_DIR) $(NAME_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(NAME_OBJS) $(LIBFT)
	@echo "$(GREY)$(NAME): $(GREEN)Executable created$(RESET)"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(NAME_INCLUDES) -c $< -o $@
	@echo "$(MAGENTA)Compiling: $(BLUE)$< -> $(GREEN)$@$(DEFAULT)"

# Clean rules
clean:
	@$(REMOVE) $(BUILD_DIR)
	@$(LIBFT_MAKE) clean
	@echo "$(GREY)Object files removed$(RESET)"

fclean: clean
	@$(REMOVE) $(NAME)
	@$(LIBFT_MAKE) fclean
	@echo "$(GREY)Executables removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
