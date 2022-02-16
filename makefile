
CC = gcc
CFLAGS = -O3 -Wall

all : main2

main2 : main2.c
	$(CC) $(CFLAGS) main2.c -o main2 -lm
	chmod 755 main2

run : main2
	./main2

.PHONY : clean
clean :
	rm -f main2
