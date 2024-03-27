NAME = push_swap
CC = cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror 

SRC = main.c sort_smalls.c actions1.c find_cost_index.c ft_parsing.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make re -C ./includes/libft
	make bonus -C ./includes/libft	
	$(CC) $(CFLAGS) $(OBJ) -L./includes/libft -lft -o push_swap	

clean:
	rm -f $(OBJ)

fclean : clean
		rm -rf $(NAME)
re: clean all
