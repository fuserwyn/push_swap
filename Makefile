NAME = push_swap

CH_NAME = checker

PS_SRCS =  ./src/push_swap.c \
			./src/operations.c \
			./src/operations_2.c \
			./src/utils.c \
			./src/argc_checker.c \
			./src/array_sortings.c \
			./src/finders.c \
			./src/algos_butterfly_sortings.c \
			./src/errors.c \
			./src/short_sortings.c \

CH_SRCS =	./src/checker.c \
			./src/operations.c \
			./src/operations_2.c \
			./src/utils.c \
			./src/argc_checker.c \
			./src/errors.c \
			./src/array_sortings.c \
			./src/checker_utils.c \

			
CC = gcc -Wall -Wextra -Werror

INCLUDES = -I.

PS_OBJS = $(PS_SRCS:.c=.o)

CH_OBJS = $(CH_SRCS:.c=.o)

$(NAME): $(PS_OBJS)
	$(MAKE) -C ./libft --silent
	$(CC) -o $(NAME) $(PS_OBJS) -L./libft -lft

$(CH_NAME): $(CH_OBJS)
	$(MAKE) -C ./libft --silent
	$(CC) -o $(CH_NAME) $(CH_OBJS) -L./libft -lft

all : $(NAME)

bonus:			${CH_NAME}

clean :
	$(MAKE) clean -C ./libft --silent
	rm -rf $(PS_OBJS)
	rm -rf $(CH_OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft --silent
	rm -rf $(NAME)
	rm -rf $(CH_NAME)

bonus : $(CH_NAME)

re : fclean all

rebonus: fclean bonus
