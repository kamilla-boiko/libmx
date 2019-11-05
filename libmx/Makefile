LIB = libmx.a

INC = libmx.h
INCI = inc/libmx.h

SRC = mx_printchar.c mx_printstr.c mx_strlen.c mx_print_strarr.c
SRCS = src/mx_printchar.c src/mx_printstr.c src/mx_strlen.c src/mx_print_strarr.c

OBJ = mx_printchar.o mx_printstr.o mx_strlen.o mx_print_strarr.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rcs $(LIB) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(LIB)
	@rm -rf ./obj

clean:
	@rm -rf $(INC)
	@rm -rf $(SRC)

reinstall: uninstall all
