
CC = gcc

%.o : %.c
	$(CC) -c $< -o $@ 

main : main.o enums.o dialogue.o heroine.o event.o
	$(CC) $^ -o $@

test : main
	main

clean : 
	rm -f core *.o main
