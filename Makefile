# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraspors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 01:09:25 by mraspors          #+#    #+#              #
#    Updated: 2022/04/15 04:17:16 by mraspors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
FILES		=	push_swap.c

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# Sources and objects
SRC			=	$(FILES)

OBJS_SRC	=	$(SRC:.c=.o)

OBJS		=	$(OBJS_SRC)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

NAME		=	push_swap

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): $(OBJS)
		$(LIBFT) 
		$(GCC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all