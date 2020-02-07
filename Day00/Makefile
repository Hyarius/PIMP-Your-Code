NAME = pimp_my_code

INC_DIR = $(shell find includes -type d)
SRC_DIR = $(shell find src -type d)
OBJ_DIR = obj

SRC = main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

CFLAG = -Werror -Wextra -Wall
IFLAG = $(foreach dir, $(INC_DIR), -I $(dir) )

all		: $(NAME)

## -c = definit les fichiers sources a compiler
## -o = change le nom du fichier d'output
## $@ = la cible de la regle
## $< = la premiere dependance de la regle
## $^ = les dependances de la regle
$(OBJ_DIR)/%.o : %.c
	@gcc $(CFLAG) $(IFLAG) -c $< -o $@

$(NAME)	: $(OBJ)
	@gcc $(CFLAG) $(IFLAG) $(OBJ) -o $@

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

show	:
	echo "SRC_DIR = \n$(SRC_DIR)"
