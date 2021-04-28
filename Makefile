EXEC		=	libftprintf.a
CC			=	gcc $(CFLAGS)
CFLAGS		=	-Wall -Werror -Wextra
LIB			=	ar rcs
INC			=	-Iinc
RM			=	rm -rf

SRC_DIR		=	src/
SRC_FILES	=	ft_printf.c \
				print_utils.c \
				proc_1.c \
				proc_2.c \
				proc_utils.c \
				read.c \
				utils_nbr.c \
				utils_str.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_DIR		=	obj/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(MAKE) -C libft/
	cp libft/libft.a $(EXEC)
	$(LIB) $(EXEC) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(INC) -c $< -o $@

clean:
	$(MAKE) clean -C libft/
	$(RM) $(OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C libft/
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
