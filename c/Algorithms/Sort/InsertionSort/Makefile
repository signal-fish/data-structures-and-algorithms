objects=test_insertion_sort.o insertion_sort.o

test_insertion_sort:$(objects)
	gcc -Wall -o test_insertion_sort $(objects) -lcheck -lsubunit -lm

test_insertion_sort.o:test_insertion_sort.c
	gcc -c test_insertion_sort.c

insertion_sort.o:insertion_sort.c
	gcc -c insertion_sort.c

.PHONY:check run

check:
	checkmk test_insertion_sort.ck > test_insertion_sort.c

run:
	./test_insertion_sort