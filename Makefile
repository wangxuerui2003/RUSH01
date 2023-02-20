# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:16:15 by wxuerui           #+#    #+#              #
#    Updated: 2023/02/20 13:30:47 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

NAME		=	rush01
CC			=	gcc
HEADER		=	-I$(INCLUDE_DIR)
CFLAGS		=	-Wall -Wextra -Werror $(HEADER) -pthread
# CFLAGS		+=	-fsanitize=address -g3
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INCLUDE_DIR	=	includes/

#sources

SRC_FILES	=	main \
				init \
				solve \
				utils

SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#Colors

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
RESET		=	\033[0m

#######

all:
				@mkdir -p $(OBJS_DIR)
				@make $(NAME)

$(OBJS):		$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo ".\c"

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "\n$(GREEN)$(NAME) was created$(RESET)"

clean:
				@rm -rf $(OBJS_DIR)
				@echo "$(BLUE)$(NAME): $(YELLOW)object files are cleaned$(RESET)"

fclean:			clean
				@rm -rf $(NAME)
				@echo "$(BLUE)$(NAME): $(MAGENTA)$(NAME) was deleted$(RESET)"

re:				fclean all

.PHONY:			all bonus create_libft clean fclean re