objects=test_linked_list_stack.o linked_list_stack.o

test_linked_list_stack:$(objects)
	gcc -Wall -o test_linked_list_stack $(objects) -lcheck -lsubunit -lm

test_linked_list_stack.o:test_linked_list_stack.c
	gcc -c test_linked_list_stack.c

linked_list_stack.o:linked_list_stack.c
	gcc -c linked_list_stack.c

.PHONY:check run

check:
	checkmk test_linked_list_stack.ck > test_linked_list_stack.c

run:
	./test_linked_list_stack