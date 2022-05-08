# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraspors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 01:09:25 by mraspors          #+#    #+#              #
#    Updated: 2022/05/08 05:39:52 by mraspors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
FILES		=		validation/check_errors.c validation/check_spaces.c validation/dup_push.c\
					validation/error_dup.c validation/error_non_num.c validation/parse.c\
					sort/check_3_swap.c sort/check_pos.c sort/push_back.c sort/sort_3.c\
					sort/sort_5.c sort/sort_more.c sort/sort.c\
					moves/pa.c moves/pb.c moves/ra.c moves/rb.c moves/rr.c\
					moves/rra.c moves/rrb.c moves/rrr.c moves/sa.c moves/sb.c moves/ss.c\
					list_operations/deleteNode.c list_operations/find_last.c\
					list_operations/find_pre_last.c list_operations/push.c\
					helpers/check_sort.c helpers/errors_for_pos.c helpers/find_min_node.c\
					helpers/find_pos.c helpers/list_size.c helpers/reset_i.c\
					calc_moves/count_moves.c calc_moves/find_max.c calc_moves/find_min.c\
					push_swap.c\

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