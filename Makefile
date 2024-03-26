CC = cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra #-Werror 

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)

$(OBJ):
	
	make re -C ./includes/libft
	make bonus -C ./includes/libft
	
	$(CC) $(CFLAGS) $(SRC) -L./includes/libft -lft -o push_swap	

clean:
	rm -f $(OBJ)

re:clean all
