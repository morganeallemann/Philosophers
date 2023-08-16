# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:53:11 by inaranjo          #+#    #+#              #
#    Updated: 2023/07/18 11:41:13 by inaranjo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#-------------------------- SOURCES -------------------------------------------#
SRCS 		=	main.c init.c utils.c

#--------------------------	VARIABLES -----------------------------------------#

NAME		= philo

OBJS		= ${SRCS:.c=.o}

CC			= gcc -pthread

CFLAGSDDBUG	= -Wall -Wextra -Werror -I. -Iincludes -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -I. -Iincludes -g3

#-------------------------- COMMANDES -----------------------------------------#

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@printf $(UP)$(CUT)

subsystems :
	@echo $(B)
	make -C all

$(NAME): $(OBJ)
	@echo $(Y)Compiling [$(SRC)]...$(X)
	@echo $(G)Finished [$(SRC)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@rm -f $(OBJ)
	@echo $(R)Removed [$(OBJ)]$(X)


fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re
