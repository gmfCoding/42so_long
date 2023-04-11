# SOURCE FILES
SRCS = 	main.c

INCS = 	inc/*.h \
		mlx/*.h

OBJ = $(patsubst %.c,$(OBJDIR)%.o, $(SRCS))
INCF = -I ./inc -I ./libft -I ./mlx 


MLX = mlx/libmlx.a
LIBFT = libft/libft.a

# TARGET NAME AND VARIBLES
NAME = so_long

OBJDIR = obj/
CC = cc
LFLAGS = -Llibft -lft -Lmlx -lmlx 
WFLAGS = -Wall -Wextra -Werror
GFLAGS = -g
CFLAGS = $(WFLAGS)
CCC = $(CC) $(CFLAGS) $(INCF) $(GFLAGS)  


all: $(NAME)

# BUILD LIBRARY
$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(info $(OBJ))

*.c: $(INCS) $(LIBFT) $(MLX) $(OBJDIR)

# COMPILE SOURCES
$(OBJDIR)%.o: %.c
	@$(CCC) -c $< -o $@
	@echo "Compiled: $<"

$(LIBFT):
	@make -s -C libft

$(MLX):
	@make -s -C mlx

# CLEANING
re: fclean all

fclean: clean mclean
	@echo "Full clean!"
	@-rm -f $(NAME)

fdclean: dclean fclean

dclean:
	make -s -C libft fclean
clean:
	@-rm -rf $(OBJDIR)
	@rm -rf ./libtmp

# EXECUTE MAIN.O TARGET
run: $(NAME)
	@echo "Executing main:\n"
	@./$(NAME)
	@echo "\n\nEnd of program!"

.PHONY: clean fclean mclean $(NAME) all re run
