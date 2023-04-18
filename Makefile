SRCSF =	main.c example.c
INCSF =	example.h
OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a gnl/libgnl.a mlx/libmlx.a

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/
DIRLIB = lib/

SRCS = $(patsubst %.c,$(DIRSRC)%.c, $(SRCSF))
OBJS = $(patsubst %.c,$(DIROBJ)%.o, $(SRCSF))
INCS = $(patsubst %.h,$(DIRINC)%.h, $(INCSF))
LIBS = $(patsubst %.a,$(DIRLIB)%.a, $(SRCSF))
LIBNAMES = $(basename $(notdir $(LIBSF)))
$(info $(LIBNAMES))

NAME = program
all: $(NAME)
CC = cc

CFLAGS = $(DFLAGS) -Lmlx -lmlx -Llibft -lft -Lgnl -lgnl -lz -lm -framework OpenGL -framework AppKit
OFLAGS = $(DFLAGS) -Imlx -I$(DIRINC)

mlx: mlx/libmlx.a  
mlx/libmlx.a:
	make -s -C mlx DFLAGS=$(DFLAGS)
ft: libft/libft.a  
libft/libft.a: 
	make -s -C libft DFLAGS=$(DFLAGS)
gnl: gnl/libgnl.a
gnl/libgnl.a:
	make -s -C gnl DFLAGS=$(DFLAGS)

$(NAME): $(OBJS) mlx ft gnl 
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(DIROBJ)%.o: $(DIRSRC)%.c $(INCS) 
	@mkdir -p $(DIROBJ)
	$(CC) $(OFLAGS) -o $@ -c $<


fclean: clean
	@-rm -f $(NAME)
	@-make -s -C mlx clean
	@-make -s -C gnl fclean
	@-make -s -C libft fclean

clean:
	@-rm -rf $(DIROBJ)

.PHONY: all $(NAME) fclean clean 
