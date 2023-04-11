SRCSF =	main.c example.c
INCSF =	example.h
OBJSF = $(patsubst %.c,%.o, $(SRCSF))

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/

SRCS = $(patsubst %.c,$(DIRSRC)%.c, $(SRCSF))
OBJS = $(patsubst %.c,$(DIROBJ)%.o, $(SRCSF))
INCS = $(patsubst %.h,$(DIRINC)%.h, $(INCSF))

NAME = program
all: $(NAME)
CC = cc
CFLAGS = -g -Lmlx -lmlx -framework OpenGL -framework AppKit

OFLAGS = -g -Imlx -I$(DIRINC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(DIROBJ)%.o: $(DIRSRC)%.c $(INCS) 
	$(CC) $(OFLAGS) -o $@ -c $<
	
.PHONY: all $(NAME) 
