NAME = pimp_my_code

# LIB_DIR = $(shell find lib -type d -maxdepth 1 | grep 'lib/')
# INC_DIR = $(shell find includes -type d) $(foreach dir, $(LIB_DIR), $(shell find -f $(dir)/includes -type d))
LIB_DIR = lib/libft lib/mlx
INC_DIR = $(shell find includes -type d) lib/libft/includes lib/mlx/elcapitan
SRC_DIR = $(shell find src -type d)
OBJ_DIR = obj

SRC = main.c color.c image.c application.c drawing.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIB = ft mlx
FRAMEWORK = AppKit OpenGL

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

CFLAG = -fsanitize=address -g
IFLAG = $(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG = $(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )
#LFLAG = -L lib/libft -L lib/mlx -l mlx -l libft

LFLAG += $(foreach framework, $(FRAMEWORK), -framework $(framework) )

all		: $(NAME)

show	:
	@echo "SRC_DIR : $(SRC_DIR)\n"
	@echo "LIB_DIR : $(LIB_DIR)\n"
	@echo "INC_DIR : $(INC_DIR)\n"
	@echo "CFLAG : $(CFLAG)\n"
	@echo "IFLAG : $(IFLAG)\n"
	@echo "LFLAG : $(LFLAG)\n"
	@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
	@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

#@echo "LIB :$(foreach lib, $(LIB),\n\t$(lib))\n"
#LIB = ft mlx
#LFLAGS = 	$(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l$(lib) ) -framework OpenGL -framework AppKit

## -c = definit les fichiers sources a compiler
## -o = change le nom du fichier d'output
## $@ = la cible de la regle
## $< = la premiere dependance de la regle
## $^ = les dependances de la regle
$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAG) $(IFLAG) -c $< -o $@

$(NAME)	: $(OBJ)
	@gcc $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ) -o $@

debug : $(NAME)
	@./$(NAME)

install :
	make -C lib/libft
	make -C lib/mlx

re-install :
	make -C lib/libft re
	make -C lib/mlx re

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all
