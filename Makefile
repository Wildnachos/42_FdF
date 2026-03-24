# Name of the executable
NAME = fdf

# Source files
SOURCES = controls.c windows.c map_parse.c fdf.c end_process.c ft_atoi.c ft_split.c colours.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Iprintf -O3

# Linker flags
LFLAGS = -Lminilibx-linux -lmlx_Linux \
         -L/usr/lib \
         -lXext -lX11 -lm -lz

# MiniLibX settings
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a

# Rules
all: $(NAME)

$(NAME): $(OBJECTS) $(MINILIBX_LIB)
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(MINILIBX_DIR) clean

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean

# Rebuild everything
re: fclean all

# Phony targets to avoid conflicts with files
.PHONY: all clean fclean re
