objects=test_doubly_linked_list.o doubly_linked_list.o

test_doubly_linked_list:$(objects)
	gcc -Wall -o test_doubly_linked_list $(objects) -lcheck -lsubunit -lm

test_doubly_linked_list.o:test_doubly_linked_list.c
	gcc -c test_doubly_linked_list.c

doubly_linked_list.o:doubly_linked_list.c
	gcc -c doubly_linked_list.c

.PHNOY:check run

check:
	checkmk test_doubly_linked_list.ck > test_doubly_linked_list.c

run:
	./test_doubly_linked_list

