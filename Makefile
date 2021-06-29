NAME		=	libftprintf.a
CC			=	clang $(CFLAGS)
CFLAGS		=	-Wall -Werror -Wextra -fPIC
LIB			=	ar rcs
INC			=	-Iinc
RM			=	rm -rf

SRC_DIR		=	src/
SRC_FILES	=	ft_printf.c \
				proc_1.c \
				proc_2.c \
				proc_3.c \
				read.c \
				utils_base.c \
				utils_nbr.c \
				utils_print.c \
				utils_proc.c \
				utils_str.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_DIR		=	obj/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))


BSRC_DIR	=	bonus/
BSRC_FILES	=	process.c \
				read.c
BSRC		=	$(addprefix $(BSRC_DIR), $(BSRC_FILES))
BOBJ_DIR	=	bobj/
BOBJ_FILES	=	$(BSRC_FILES:.c=.o)
BOBJ		=	$(addprefix $(BOBJ_DIR), $(BOBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(BOBJ)
	@echo -n "\nNOW COMPILING LIBFT..."
	@make -s -C libft/
	@echo "\033[32m\t\t\t[OK]\033[0m"
	@cp libft/libft.a $(NAME)
	@echo -n "\nNOW GENERATING LIBFTPRINTF..."
	@$(LIB) $(NAME) $(OBJ) $(BOBJ)
	@echo "\033[32m\t\t[OK]\033[0m\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@$(CC) $(INC) -c $< -o $@

$(BOBJ_DIR)%.o: $(BSRC_DIR)%.c
	@mkdir -p bobj
	@$(CC) $(INC) -c $< -o $@

bonus: all

clean:
	@make -s clean -C libft/
	$(RM) $(OBJ_DIR) $(BOBJ_DIR)

fclean : clean
	@make -s fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
