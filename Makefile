NAME = fdf

SRCS = dda.c\
	read_data.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_split.c\
	ft_atoi.c\
	ft_strncmp.c\
	fdf.c ft_free.c

$(NAME) : $(SRCS)
	cc $(SRCS) -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit -o $(NAME)
all : $(NAME)
clean :
	rm -f  $(NAME)
fclean : clean
re : fclean all
