NAME=		liblibft.a

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d)

##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)

##Folder where he will store the .o
OBJ_DIR	=	obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##List every .c found inside SRC_DIR
##SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
SRC =	ft_atoi.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		ft_swap_float.c \
		get_next_line.c \
		ft_abs.c \
		ft_max.c \
		ft_min.c \
		ft_swap_int.c \
		ft_intparse_tab.c \
		ft_intstr_new.c \
		ft_inttab_cpy.c \
		ft_inttab_new.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isnum.c \
		ft_isprint.c \
		libft_list.c \
		libft_list2.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putinttab.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_puttab.c \
		converter.c \
		converter2.c \
		converter3.c \
		handle_converter.c \
		set_flags.c \
		set_flags_lh.c \
		t_data.c \
		t_flag_data.c \
		flag.c \
		flag2.c \
		handle_flag.c \
		ft_str_fill.c \
		ft_str_replace.c \
		ft_str_toupper.c \
		ft_strcat.c \
		ft_strcchr.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strcut.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnew_c.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_target_strncat.c \
		ft_tolower.c \
		ft_toupper.c \
		error_exit.c \
		ft_get_leaks.c \
		ft_tab_free.c \
		ft_tab_len.c \
		libft_vector.c 

##Transform and place every .o from SRC
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-Wall -Wextra -Werror

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS =

##Define the compiler to use
CC=			gcc

all:
				make $(NAME)

$(NAME):		$(OBJ) $(INC_DIR) Makefile
				@echo "Compiling $(NAME) ...\c"
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir -p $(OBJ_DIR)
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY: all clean fclean re
