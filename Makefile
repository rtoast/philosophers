NAME = philo
HEAD = ./philo.h
C_FILE = philo.c additionally.c init.c
O_FILE = $(C_FILE:.c=.o)
all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c -g -Wall -Wextra -Werror $< -o $@
clean:
	@rm -f $(O_FILE)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re