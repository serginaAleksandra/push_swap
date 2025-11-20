# Minimal Makefile for project root
NAME = push_swap

LIBFT_DIR = libft_printf
LIB = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c param_proc.c utils.c lst_utils.c rules_ss_push.c \
	rules_rr.c rules_rrr.c sort.c radix_sort.c string_parse.c
INCLUDES = -I$(LIBFT_DIR) -I.

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