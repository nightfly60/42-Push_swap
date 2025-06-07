NAME = push_swap
LIBFT_DIR = libft
OBJDIR = obj
LIBFT = $(LIBFT_DIR)/libft.a
FILES = operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c utils/checks/check_dupli.c \
	utils/checks/check_int.c utils/creation/create_list.c utils/creation/normalize.c utils/lst/ft_lstget.c utils/lst/ft_lstmax.c \
	utils/lst/ft_lstmin.c utils/lst/ft_lstsorted.c utils/lst/lst_push_swap.c utils/make_operations/apply_rotations.c \
	utils/make_operations/calculate.c utils/make_operations/extremum.c utils/make_operations/sort_three.c push_swap.c \
	utils/creation/tab_size.c utils/checks/check_args.c
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(FILES))

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: fclean clean all re
