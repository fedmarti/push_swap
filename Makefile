#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _
# ___ __|  __/   |   |  (   |    <    __/
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=  	push_swap.c \
					reformat_input.c \
					array_initiation.c \
					rename_values.c \
					ft_split.c \
					ft_strlen.c \
					push_swap_utils.c \
					push_swap_utils_2.c \
					push_swap_utils_3.c \
					push_swap_utils_4.c \
					pathfind.c \
					pathfind_2.c \
					pathfind_3.c \
					pathfind_4.c \
					pathfind_5.c \
					ps_moves.c \
					ps_moves_2.c \
					ps_moves_3.c \
					solve_low_n.c \
					solve_low_n_2.c \
					solve_5.c \
					solve_5_2.c \
					quickest_pair.c \
					quickest_pair_2.c \
					pseudo_quick_sort.c \
					pseudo_quick_sort_utils.c \
					chunk_list_utils.c \
					chunk_list_utils_2.c \
					chunk_list_utils_3.c \
					chunk_list_utils_4.c \
					insertion_sort.c \
					lis.c

B_SRCS		:= 		get_next_line.c \
					get_next_line_utils.c \
					checker.c \
					checker_2.c \
					push_swap_utils.c \
					push_swap_utils_2.c \
					push_swap_utils_3.c \
					push_swap_utils_4.c \
					reformat_input.c \
					array_initiation.c \
					rename_values.c \
					ft_split.c \
					ft_strlen.c \
					pathfind.c \
					pathfind_3.c \
					solve_low_n.c 

OBJS        := $(SRCS:.c=.o)

B_OBJS		:= $(B_SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		re ${B_OBJS}
			${CC} ${FLAGS} -o checker ${B_OBJS}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ ${RM} ./checker
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re bonus
