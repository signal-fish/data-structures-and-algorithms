objects=test_shell_sort.o shell_sort.o

test_shell_sort:$(objects)
	gcc -Wall -o test_shell_sort $(objects) -lcheck -lsubunit -lm

test_shell_sort.o:test_shell_sort.c
	gcc -c test_shell_sort.c

shell_sort.o:shell_sort.c
	gcc -c shell_sort.c

.PHONY:check run

check:
	checkmk test_shell_sort.ck > test_shell_sort.c

run:
	./test_shell_sort