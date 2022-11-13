objects=test_quick_sort.o quick_sort.o

test_quick_sort:$(objects)
	gcc -Wall -o test_quick_sort $(objects) -lcheck -lsubunit -lm

test_quick_sort.o:test_quick_sort.c
	gcc -c test_quick_sort.c

quick_sort.o:quick_sort.c
	gcc -c quick_sort.c

.PHONY:check run

check:
	checkmk test_quick_sort.ck > test_quick_sort.c

run:
	./test_quick_sort