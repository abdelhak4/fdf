NAME = fdf.a
SRCS = dda.c\
	read_data.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_split.c\
	ft_atoi.c\

OBJS = $(SRCS:.c=.o)
all:
	gcc  -c -g $(SRCS)
	ar rc $(NAME) $(OBJS)
	cc fdf.c -fsanitize=address  -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit  $(NAME)
fclean :
	rm -rf *.o $(NAME)
re : fclean all