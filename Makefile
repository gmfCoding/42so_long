SRCSF =	main.c example.c lst_readfile.c map.c vector.c vectormath.c tile.c
INCSF =	example.h
OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a gnl/libgnl.a

$(info $(OS))

ifeq ($(OS),linux)
	LIBSF += mlx-linux/mlxlib.a
else
	LIBSF += mlx/mlxlib.a
endif

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/
DIRLIB = .lib/

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

CFLAGS = $(DFLAGS) $(LIB-L) $(LIB-l) -lz -lm 
ifneq ($(OS),linux)
CFLAGS += -framework OpenGL -framework AppKit
endif

OFLAGS = $(DFLAGS) $(LIB-I) -I$(DIRINC)

$(LIBS):
	-make -s -C $(dir $@) all bonus

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(DIROBJ)%.o: $(DIRSRC)%.c $(INCS) 
	@mkdir -p $(DIROBJ)
	$(CC) $(OFLAGS) -o $@ -c $<


fclean: clean libclean libfclean
	@-rm -f $(NAME)

libclean:
	-make -s -C $(DIRLIB)mlx clean

libfclean:
	-make -s -C $(DIRLIB)gnl fclean
	-make -s -C $(DIRLIB)libft fclean
	

clean:
	@-rm -rf $(DIROBJ)

.PHONY: all $(NAME) fclean clean libclean libfclean linux
