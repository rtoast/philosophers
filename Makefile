NAME = philo
HEAD = ./philo.h
C_FILE = philo.c
O_FILE = $(C_FILE:.c=.o)
all:
	$(MAKE) -j 4
%.o: %.c $(HEAD)
	gcc -c -g -Wall -Wextra -Werror $< -o $@
clean:
	@rm -f $(O_FILE)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re