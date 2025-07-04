# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 12:39:52 by rwrobles          #+#    #+#              #
#    Updated: 2025/06/20 15:20:00 by rwrobles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

# Colors
GREEN	=	\033[0;32m
MAGENTA	=	\033[0;35m
BLUE	=	\033[0;34m
GREY	=	\033[0;90m
RESET	=	\033[0m

# Compiler and flags
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# Directories
SRC_DIR 	= 	sources
BUILD_DIR	=	build
INCLUDES	=	-Iincludes -Iincludes/libft
LIBFT_DIR	=	includes/libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a

# Source files
SRCS	=	main.c \
			memory.c \
			ops.c \
			sorts.c \
			utils.c

OBJS	=	$(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

# Targets
all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(LIBFT_A):
	@echo "$(MAGENTA)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(BUILD_DIR) $(LIBFT_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(MAGENTA)Compiling: $(BLUE)$<$(RESET)"

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(GREY)Objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREY)Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
