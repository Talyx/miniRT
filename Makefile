HEADER_DIR = ./includes

LIBFT_SRC = \
		./libft/ft_atoi.c					./libft/ft_strdup.c			\
		./libft/ft_bzero.c					./libft/ft_strjoin.c			\
		./libft/ft_calloc.c					./libft/ft_strlcat.c			\
		./libft/ft_isalnum.c					./libft/ft_strlcpy.c			\
		./libft/ft_isalpha.c					./libft/ft_strlen.c			\
		./libft/ft_isascii.c					./libft/ft_strmapi.c			\
		./libft/ft_isdigit.c					./libft/ft_strncmp.c			\
		./libft/ft_islower.c					./libft/ft_strncpy.c			\
		./libft/ft_isprint.c					./libft/ft_strnstr.c			\
		./libft/ft_isspace.c					./libft/ft_strrchr.c			\
		./libft/ft_isupper.c					./libft/ft_strtrim.c			\
		./libft/ft_itoa.c					./libft/ft_strdel.c			\
		./libft/ft_memccpy.c					./libft/ft_substr.c			\
		./libft/ft_memchr.c					./libft/ft_tolower.c			\
		./libft/ft_memcmp.c					./libft/ft_toupper.c			\
		./libft/ft_memcmp.c					./libft/ft_lstsize.c			\
		./libft/ft_memcpy.c					./libft/ft_lstnew.c			\
		./libft/ft_memmove.c					./libft/ft_lstlast.c			\
		./libft/ft_memset.c					./libft/ft_lstiter.c			\
		./libft/ft_putchar_fd.c					./libft/ft_lstdelone.c			\
		./libft/ft_putendl_fd.c					./libft/ft_lstclear.c			\
		./libft/ft_putnbr_fd.c					./libft/ft_lstadd_front.c		\
		./libft/ft_putstr_fd.c					./libft/ft_lstadd_back.c		\
		./libft/ft_split.c					./libft/ft_strequ.c			\
		./libft/ft_strchr.c					./libft/ft_ssplit.c			\
		./libft/ft_strcpy.c					./libft/ft_atof.c			\
		./libft/ft_str_c_count.c				./libft/libft.h

SRC=	./srcs/main.c \
		./srcs/figure/plane.c \
		./srcs/figure/cylinder.c \
		./srcs/utils/error_exit.c \
		./srcs/utils/hook.c \
		./srcs/utils/bmp.c \
		./srcs/utils/clean.c \
		./srcs/utils/check.c \
		./srcs/geometry/vector.c	\
		./srcs/geometry/vector2.c \
		./srcs/geometry/figure_intersect.c \
		./srcs/geometry/ray_traycing.c \
		./srcs/geometry/sphere_intersection.c \
		./srcs/geometry/vec_normal.c \
		./srcs/geometry/plane_intersection.c \
		./srcs/geometry/square_intersection.c \
		./srcs/geometry/triangle_intersect.c \
		./srcs/geometry/cylinder_intersection.c \
		./srcs/parser/parser_elements.c \
		./srcs/parser/parser_utils1.c \
		./srcs/parser/parser.c \
		./srcs/scene/camera.c \
		./srcs/light/color.c \
		./srcs/light/color2.c \
		./srcs/light/light.c \
		./srcs/light/shadow.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

HEADERS = \
	./includes/element.h				\
	./includes/light.h				\
	./includes/minirt.h				\
	./includes/parser.h				\
	./includes/ray_traycing.h			\
	./includes/rt_struct.h				\
	./includes/scene.h				\
	./includes/utils.h				\
	./includes/vector.h				\
	./get_next_line/get_next_line.h			\

OBJ= 	$(SRC:.c=.o)

NAME= minirt

LIBMLX = libmlx.a

MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11

LIBFT = libft.a

FTFLAGS= -Llibft -lft

GCC = clang

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

%.o: %.c Makefile $(HEADERS)
	$(GCC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT_SRC) 
	make -C ./minilibx-linux
	make -C ./libft
	$(GCC) -g $(OBJ)  $(CFLAGS)  -I $(HEADER_DIR) $(MLXFLAGS) $(FTFLAGS) -lm -o $(NAME) 

all : $(NAME)

clean : 
	$(RM) $(OBJ)
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean: clean
	$(RM)	$(NAME)
	make clean -C ./minilibx-linux
	make fclean -C ./libft
norm:
	norminette $(SRC)
	make fclean -c ./minilibx-linux
	make fclean -c ./libft
re: fclean all

.PHONY: all clean fclean re
	
