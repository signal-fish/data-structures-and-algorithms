objects=test_array_stack.o array_stack.o

test_array_stack:$(objects)
	gcc -Wall -o test_array_stack $(objects) -lcheck -lsubunit -lm

test_array_stack.o:test_array_stack.c
	gcc -c test_array_stack.c

array_stack.o:array_stack.c
	gcc -c array_stack.c

.PHONY:check run

check:
	checkmk test_array_stack.ck > test_array_stack.c

run:
	./test_array_stack