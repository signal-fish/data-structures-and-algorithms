objects=test_bubble_sort.o bubble_sort.o

test_bubble_sort:$(objects)
	gcc -Wall -o test_bubble_sort $(objects) -lcheck -lsubunit -lm

test_bubble_sort.o:test_bubble_sort.c
	gcc -c test_bubble_sort.c

bubble_sort.o:bubble_sort.c
	gcc -c bubble_sort.c

.PHONY:check run

check:
	checkmk test_bubble_sort.ck > test_bubble_sort.c

run:
	./test_bubble_sort