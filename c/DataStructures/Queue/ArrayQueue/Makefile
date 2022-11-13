objects=test_array_queue.o array_queue.o

test_array_queue:$(objects)
	gcc -Wall -o test_array_queue $(objects) -lcheck -lsubunit -lm

test_array_queue.o:test_array_queue.c
	gcc -c test_array_queue.c

array_queue.o:array_queue.c
	gcc -c array_queue.c

.PHONY:check run

check:
	checkmk test_array_queue.ck > test_array_queue.c

run:
	./test_array_queue