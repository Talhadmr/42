CC = gcc

NAME = so_long


CFLAGS = -Werror -Wall -Wextra


GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)

SRC = 	main.c\
		put_image.c\
		map_read.c\
		map_init.c\
		free.c\
		ft_action.c\
		map_check.c\
		file_name.c\
		map_check2.c\
		map_check3.c\
		ob_check.c

OBJS := $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(GNLOBJS)
	make -C mlx
	$(CC) $(OBJS) $(GNLOBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f ${OBJS} $(NAME)
	rm -rf ./gnl/*.o

re: fclean ${NAME}