SRCS	=	main.c
INCS = test.h


OBJS = $(patsubst %.c,obj/%.o, $(SRCS))

NAME = program
all: $(NAME)

CC = cc
CFLAGS = -g -Lmlx -lmlx -framework OpenGL -framework AppKit

CCC = cc
CCFLAGS = -g -Imlx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.c: test.h
	@echo "Header changed!"

obj/%.o: %.c 
	$(CCC) $(CCFLAGS) -o $@ -c $<

.PHONY: all $(NAME) 
