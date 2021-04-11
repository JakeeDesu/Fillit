L_C = ./libft/*.c
L_O = *.o
LIB_NAME = libft.a
C_FILES =	blankcell.c check_all.c clear_cord.c count_blank.c count_tetris.c create_map.c fill_map.c ft_sqrt.c line_valid.c main.c map_upgrade.c paste_map.c print_map.c re_zero.c test_matching.c test_valid.c tetris_valid.c to_points.c v_reader.c validate.c 
O_FILES =	blankcell.o check_all.o clear_cord.o count_blank.o count_tetris.o create_map.o fill_map.o ft_sqrt.o line_valid.o main.o map_upgrade.o paste_map.o print_map.o re_zero.o test_matching.o test_valid.o tetris_valid.o to_points.o v_reader.o validate.o
NAME = fillit

all : $(NAME)

$(NAME) :
	gcc -Werror -Wall -Wextra -c $(L_C)
	ar rc $(LIB_NAME) $(L_O)
	ranlib $(LIB_NAME)
	gcc -c $(C_FILES)
	gcc -o $(NAME) $(O_FILES) $(LIB_NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(LIB_NAME)

re : fclean all
