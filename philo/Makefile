CC = gcc -Wall -Wextra -Werror -pthread #-fsanitize=thread -g3

HEADERS = philo.h

NAME = philo

SRC = philo.c\
		./ext_func/ft_atol.c \
		./parsing/parsing_args.c\
		./creating_nodes/create_nodes.c\
		./init_struct/init_struct.c\
		./protect_free/protect.c\
		./ext_func/ft_lstadd_back.c \
		./ext_func/ft_lstnew.c\
		./ext_func/ft_lstlast.c \
		./dining_reso/dining_philos.c \
		./dining_reso/converting_time/sec_tomilsec.c \
		# ./ext_func/ft_lstadd_front.c \
		# ./ext_func/ft_lstsize.c \
		# ./ext_func/ft_lstclear.c\
		# ./ext_func/ft_strlen.c\
		# ./ext_func/utils.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(HEADERS) Makefile
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
