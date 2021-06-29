EXEC		=	libft.a
CC			=	gcc $(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -c
LIB			=	ar rcs
RM			=	rm -rf

SRC			=	ft_atoi.c \
				ft_abs.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_free_array_of_pointers.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isws.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_nbrlen.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_base.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsdup.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_wordcount.c
OBJ_DIR		=	obj/
OBJ_FILES	=	$(SRC:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

BSRC		= 	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c
BOBJ_FILES	=	$(BSRC:.c=.o)
BOBJ		=	$(addprefix $(OBJ_DIR), $(BOBJ_FILES))

# For so target
SSRC		=	$(SRC) $(BSRC)
SOBJ_DIR	=	sobj/
SOBJ_FILES	=	$(SSRC:.c=.o)
SOBJ		=	$(addprefix $(SOBJ_DIR), $(SOBJ_FILES))

all: $(EXEC) bonus

$(EXEC): $(OBJ)
	@$(LIB) $(EXEC) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@$(CC) $< -o $@

bonus: $(BOBJ)
	@$(LIB) $(EXEC) $(BOBJ)

$(BOBJ_DIR)%.o: $(BSRC_DIR)%.c
	@$(CC) $< -o $@

so: $(SOBJ)
	@gcc -shared -o libft.so $(SOBJ)

$(SOBJ_DIR)%.o: $(SSRC_DIR)%.c
	@mkdir -p sobj
	@$(CC) -fPIC $< -o $@

clean: 
	$(RM) $(OBJ_DIR) $(SOBJ_DIR)

fclean: clean
	$(RM) $(EXEC) libft.so

re: fclean all

.PHONY: all bonus so clean fclean re
