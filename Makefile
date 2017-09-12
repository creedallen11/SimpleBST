CC=gcc
CFLAGS=-I.
DEPS = bst.h
OBJ = bst.o tests.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tests: $(OBJ)
	$(CC) -o tests bst.c tests.c -I.


clean:
	rm -f *.o