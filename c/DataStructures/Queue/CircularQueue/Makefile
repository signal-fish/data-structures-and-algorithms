objects=test_circular_queue.o circular_queue.o

test_circular_queue:$(objects)
	gcc -Wall -o test_circular_queue $(objects) -lcheck -lsubunit -lm

test_circular_queue.o:test_circular_queue.c
	gcc -c test_circular_queue.c

circular_queue.o:circular_queue.c
	gcc -c circular_queue.c

.PHONY:check run memcheck

check:
	checkmk test_circular_queue.ck > test_circular_queue.c

run:
	./test_circular_queue

memcheck:
	valgrind --leak-check=full ./test_circular_queue --show-leak-kinds=all