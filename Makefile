SRCS = main.c backtracking.c backtracking_functions.c debug.c init_tab.c
NAME = skyscraper_puzzle_solver

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)
	ar rc $(NAME) *.o

clean :
	rm -f *.o

fclean : clean
	clean
	rm -f &(NAME)

re : fclean
	fclean
	all
