SRCS_DIR	= ./srcs

OBJS_DIR	= ./objs

SRCS		= main.c parser.c execute.c util/ft_split.c util/ft_calloc.c util/ft_memset.c util/ft_getenv.c util/ft_strlen.c util/ft_strncmp.c util/ft_free_array.c util/ft_strcat.c util/ft_strdupcat.c path.c pipes.c error.c

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

NAME		= pipex

CC			= clang-9 

CFLAGS		= -Wall -Werror -Wextra -g

RM			= rm -rf

INCLUDES	= -I ./includes

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		mkdir -p $(OBJS_DIR)/util
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
