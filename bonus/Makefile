##
## EPITECH PROJECT, 2018
## malloc
## File description:
## malloc
##

NAME		= visual_memory

SRCS		= main.c		\
		  lib/calloc.c		\
		  lib/free.c		\
		  lib/make_call_sbrk.c	\
		  lib/malloc.c		\
		  lib/realloc.c		\
		  lib/show_alloc_mem.c	\
		  ncurses/arrow.c	\
		  ncurses/block.c	\
		  ncurses/bottom.c	\
		  ncurses/display.c	\
		  ncurses/init.c	\
		  ncurses/title.c	\
		  ncurses/windows.c	\

OBJS		= $(addprefix sources/, $(SRCS:.c=.o))

CC		= gcc

RM		= rm -f

CFLAGS		= -I ../includes/ -I includes/
CFLAGS		+= -fpic
CFLAGS		+= -Wall -Wextra
CFLAGS		+= -std=gnu99 -lncurses

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
