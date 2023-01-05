CC = gcc
CFLAGS = -Wall -g 

.PHONY: clean all
 

all: isort txtfind

isort: isort.c
	$(CC) $(CFLAGS) isort.c -o isort

txtfind: txtfind.c
	$(CC) $(CFLAGS) txtfind.c -o txtfind

clean:
	rm -f *.o *.a isort txtfind
