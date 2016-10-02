COMPIL = gcc
FLAG = -Wall
NAME = raycaster

all: $(NAME)

json_parser.o : json_parser.h json_parser.c
	$(COMPIL) -c $(FLAG) json_parser.c

$(NAME).o: $(NAME).c
	$(COMPIL) -c $(FLAG) $(NAME).c

$(NAME): $(NAME).o json_parser.o
	$(COMPIL) $(FLAG) $(NAME).o json_parser.o -o $(NAME)

clean:
	rm *.o $(NAME)
