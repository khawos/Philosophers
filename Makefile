# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 05:10:58 by amedenec          #+#    #+#              #
#    Updated: 2025/03/24 07:13:52 by amedenec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.

# Couleurs
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m
BOLD = \033[1m

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC = main.c \
      parsing.c \
      start_run.c \
	  init.c \
	  utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking object files...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation complete! ✅$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully! ✅$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Object directory created. $(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files cleaned. 🧹$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -rf $(NAME)
	@echo "$(RED)Executable removed. 🗑️$(RESET)"

re: fclean all
