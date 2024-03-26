CC = cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra #-Werror 

SRC = main.c sort_smalls.c actions1.c find_cost_index.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)

$(OBJ):
	
	make re -C ./includes/libft
	make bonus -C ./includes/libft
	
	$(CC) $(CFLAGS) $(SRC) -L./includes/libft -lft -o push_swap	

clean:
	rm -f $(OBJ)

re:clean all
