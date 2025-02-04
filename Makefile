CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =  mov_one.c  mov_three.c  mov_tow.c  push_swap.c  push_utils.c puch_utils_tow.c ft_split.c 
NAME = push_swap
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all