SRCS =  $(shell find "." -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = pipex
CC	= gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME) : ${SRCS}
	@${CC} ${CFLAGS} -o ${NAME} ${SRCS}
all: ${NAME}
clean: 
		@${RM} ${NAME}
fclean: clean
		${RM} ${NAME}
re: fclean all
.PHONY:  all clean fclean