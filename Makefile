SRCSF =	main.c lst_readfile.c map.c vector.c vector_math.c tile.c render.c \
		texture.c theme.c input.c vector_math_extra.c map_verify.c map_verify_fill.c \
		render_util.c rules.c debug.c error.c

OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a gnl/libgnl.a ftprintf/libftprintf.a

ifndef $(OS)
OS := $(shell uname)
endif

$(info Compiling for OS:$(OS))

ifeq ($(OS),Linux)
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

OFLAGS = $(DFLAGS)  $(LIB-I) -I$(DIRINC)
CFLAGS = $(DFLAGS)  $(LIB-L) $(LIB-l) -lz -lm 

ifeq ($(DEBUG),1)
OFLAGS += -g -fsanitize=address
CFLAGS += -g -fsanitize=address
endif

ifneq ($(OS),Linux) 
CFLAGS += -framework OpenGL -framework AppKit 
else 
CFLAGS += -lX11 -lXext
OFLAGS += -DKEYMAP_LINUX
endif

# RULES
all: $(NAME)

# OBJ TO PROJECT
$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $@

# SOURCE TO OBJ
$(OBJS): $(DIROBJ)%.o : $(DIRSRC)%.c $(INCS)
	@mkdir -p $(DIROBJ)
	$(CC) $(OFLAGS) -o $@ -c $<

# COMPILE LIBS
$(LIBS):
	@-echo "\n${GREEN}Compiling Library: ${BLUE}$@ ${NC}"
	@if [ "$(notdir $@)" = "libft.a" ]; then \
		make -s -C $(dir $@) all bonus; \
	else \
		make -s -C $(dir $@) all; \
	fi

# CLEANING
fclean: libclean clean
	-rm -f $(NAME)
	@-echo "${GREEN}DONE CLEANING!${NC}"

libclean_cleanf = $(dir $(shell find $(DIRLIB) -name "Makefile" -and -not -path "*mlx*"))
libclean_clean = $(dir $(shell find $(DIRLIB) -name "Makefile" -and -path "*mlx*"))
libclean:
	@-echo "\n${GREEN}Cleaning Libraries: ${CYAN}$(basename $(libclean_cleanf)) $(basename $(libclean_clean))${NC}"
	@-$(foreach dir,$(libclean_cleanf),echo "\n${GREEN}Cleaning: ${CYAN} $(dir) ${NC}";make -i --no-print-directory -C $(dir) clean fclean;)
	@-$(foreach dir,$(libclean_clean),echo "\n${GREEN}Cleaning: ${CYAN} $(dir) ${NC}";make -i --no-print-directory -C $(dir) clean;)

clean:
	-rm -rf $(DIROBJ)

.PHONY: all $(NAME) fclean clean libclean

# COLORS
BLUE = \033[1;34m
CYAN = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m
