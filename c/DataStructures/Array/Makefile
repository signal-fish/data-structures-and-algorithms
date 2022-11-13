objects=test_array.o array.o

test_array:$(objects)
	gcc -Wall -o test_array $(objects) -lcheck -lsubunit -lm

test_array.o:test_array.c
	gcc -c test_array.c

array.o:array.c
	gcc -c array.c

.PHONY:check run

check:
	checkmk test_array.ck > test_array.c

run:
	./test_array