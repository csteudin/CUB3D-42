FLAGS = -Werror -Wall -Wextra
NAME = libft.a
CC = cc
SRC =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_tolower.c ft_toupper.c ft_strdup.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_memchr.c ft_memcmp.c \
		ft_strncmp.c ft_strlcpy.c ft_striteri.c ft_strchr.c ft_strmapi.c ft_calloc.c ft_memmove.c \
		ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c \
		ft_strtrim.c ft_split.c ft_strcpy.c ft_strcpy.c ft_strcat.c ft_strncat.c ft_strcmp.c ft_strstr.c \
		ft_strequ.c ft_strnequ.c ft_strmap.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_memccpy.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_printf.c \
		ft_printf_utils.c ft_printf_handles.c get_next_line.c ft_strncpy.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME) a.out

re : fclean all
