# Minimal Makefile for project root
NAME = push_swap
LIBFT_DIR = libft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -I.
SRC = main.c utils.c rules.c
LIB = $(LIBFT_DIR)/libft.a

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIB) $(INCLUDES) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re