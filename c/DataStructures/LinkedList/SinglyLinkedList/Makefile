objects=test_singly_linked_list.o singly_linked_list.o

test_singly_linked_list:$(objects)
	gcc -Wall -o test_singly_linked_list $(objects) -lcheck -lsubunit -lm

test_singly_linked_list.o:test_singly_linked_list.c
	gcc -c test_singly_linked_list.c

singly_linked_list.o:singly_linked_list.c
	gcc -c singly_linked_list.c

.PHONY:check run

check:
	checkmk test_singly_linked_list.ck > test_singly_linked_list.c

run:
	./test_singly_linked_list