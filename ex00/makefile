NAME = rush-02
CC = cc
CWARNS = -Wall -Wextra -Werror

SOURCES = \
	../src/main.c \
	../libs/dict/dict_get_value.c \
	../libs/error/error_print.c \
	../libs/file/file_read_as_string.c \
	../libs/number/number_parse.c \
	../libs/number/number_print_in_words.c \
	../libs/std/std_putchar.c \
	../libs/std/std_putstr.c \
	../libs/std/std_realloc_char.c \
	../libs/std/std_strcmp.c \
	../libs/std/std_strcpy.c \
	../libs/std/std_strlen.c \

OBJECTS = \
	main.o \
	dict_get_value.o \
	error_print.o \
	file_read_as_string.o \
	number_parse.o \
	number_print_in_words.o \
	std_putchar.o \
	std_putstr.o \
	std_realloc_char.o \
	std_strcmp.o \
	std_strcpy.o \
	std_strlen.o \

all: $(NAME)

$(NAME): 
	cd build && $(CC) $(CWARNS) -c $(SOURCES)
	cd build && $(CC) $(CWARNS) -o $(NAME) $(OBJECTS)

clean:
	rm -f build/*.o \

fclean: clean
	rm ./build/rush-02

re: fclean all