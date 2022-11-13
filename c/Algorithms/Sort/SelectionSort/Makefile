objects=test_selection_sort.o selection_sort.o

test_selection_sort:$(objects)
	gcc -Wall -o test_selection_sort $(objects) -lcheck -lsubunit -lm

test_selection_sort.o:test_selection_sort.c
	gcc -c test_selection_sort.c

selection_sort.o:selection_sort.c
	gcc -c selection_sort.c

.PHONY:check run

check:
	checkmk test_selection_sort.ck > test_selection_sort.c

run:
	./test_selection_sort