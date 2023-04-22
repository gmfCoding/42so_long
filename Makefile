SRCSF =	main.c lst_readfile.c map.c vector.c vectormath.c tile.c render.c sprite.c texture.c theme.c

OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a gnl/libgnl.a

ifeq ($(OS),linux)
	LIBSF += mlx-linux/libmlx.a
else
	LIBSF += mlx/libmlx.a
endif

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/
DIRLIB = .lib/

# All relative to Makefile's folder
SRCS = $(patsubst %.c,$(DIRSRC)%.c, $(SRCSF))
OBJS = $(patsubst %.c,$(DIROBJ)%.o, $(SRCSF))
LIBS = $(patsubst %.a,$(DIRLIB)%.a, $(LIBSF))
INCS = $(shell find $(DIRINC) -name "*.h")

LIB-I = $(patsubst %,-I%,$(dir $(LIBS)))
LIB-l = $(subst lib,-l,$(basename $(notdir $(LIBSF))))
LIB-L = $(patsubst %,-L$(DIRLIB)%, $(dir $(LIBSF)))

NAME = program
CC = cc

OFLAGS = $(DFLAGS) $(LIB-I) -I$(DIRINC)
CFLAGS = $(DFLAGS) $(LIB-L) $(LIB-l) -lz -lm 

ifneq ($(OS),linux) 
CFLAGS += -framework OpenGL -framework AppKit 
else 
CFLAGS += -lX11 -lXext
endif

# RULES
all: $(NAME)

# OBJ TO PROJECT
$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(CFLAGS) -o $@

# SOURCE TO OBJ
$(OBJS): $(DIROBJ)%.o : $(DIRSRC)%.c $(INCS) 
	@mkdir -p $(DIROBJ)
	$(CC) $(OFLAGS) -o $@ -c $<

# COMPILE LIBS
$(LIBS):
	@-echo "\n${GREEN}Compiling Libraries:${BLUE}$@ ${NC}"
ifeq ($(findstring mlx,$@),mlx)
	@-echo "\n${GREEN}NO BONUS${BLUE}$@ ${NC}"
	@-make -s -C $(dir $@) all
else
	@-echo "\n${GREEN}DOING: BONUS${BLUE}$@ ${NC}"
	@-make -s -C $(dir $@) all bonus
endif

# CLEANING
fclean: libclean clean
	-rm -f $(NAME)
	@-echo "${GREEN}DONE CLEANING!${NC}"

makedirs = $(dir $(shell find .lib -name "Makefile"))
libclean:
	@-echo "\n${GREEN}Cleaning Libraries: ${CYAN}$(basename $(makedirs))${NC}"
	@-$(foreach dir,$(makedirs),echo "\n${GREEN}Cleaning: ${CYAN} $(dir) ${NC}";make -i --no-print-directory -C $(dir) clean fclean;)

clean:
	-rm -rf $(DIROBJ)

.PHONY: all $(NAME) fclean clean libclean linux

# COLORS
BLUE = \033[1;34m
CYAN = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m
