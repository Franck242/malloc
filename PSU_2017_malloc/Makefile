##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile all source file
##

GCC		= gcc -lpthread

RM		= rm -rf

CFLAGS		= -I./header

LDFLAGS		= -shared

NAME		= libmy_malloc.so

SRCS		= src/show_alloc_mem.c \
		  src/malloc_fit.c \
		  src/calloc.c \
		  src/all_functions.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(GCC) $(CFLAGS) -fpic -c $(SRCS)
	mv *.o src
	$(GCC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *.o
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
