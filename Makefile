SRCSF =	main.c example.c
INCSF =	example.h
OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a gnl/libgnl.a mlx/libmlx.a

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/
DIRLIB = lib/

# All relative to Makefile's folder
SRCS = $(patsubst %.c,$(DIRSRC)%.c, $(SRCSF))
OBJS = $(patsubst %.c,$(DIROBJ)%.o, $(SRCSF))
INCS = $(patsubst %.h,$(DIRINC)%.h, $(INCSF))
LIBS = $(patsubst %.a,$(DIRLIB)%.a, $(LIBSF))

LIB-I = $(patsubst %,-I%,$(dir $(LIBS)))
LIB-l = $(subst lib,-l,$(basename $(notdir $(LIBSF))))
LIB-L = $(patsubst %,-L$(DIRLIB)%, $(dir $(LIBSF)))

NAME = program
all: $(NAME)
CC = cc

CFLAGS = $(DFLAGS) $(LIB-L) $(LIB-l) -lz -lm -framework OpenGL -framework AppKit
OFLAGS = $(DFLAGS) $(LIB-I) -I$(DIRINC)

$(LIBS):
	@make -s -C $(dir $@)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(DIROBJ)%.o: $(DIRSRC)%.c $(INCS) 
	@mkdir -p $(DIROBJ)
	$(CC) $(OFLAGS) -o $@ -c $<


fclean: clean libclean libfclean
	@-rm -f $(NAME)

libclean:
	@-make -s -C $(DIRLIB)/mlx clean

libfclean:
	@-make -s -C $(DIRLIB)/gnl fclean
	@-make -s -C $(DIRLIB)/libft fclean
	

clean:
	@-rm -rf $(DIROBJ)

.PHONY: all $(NAME) fclean clean 
