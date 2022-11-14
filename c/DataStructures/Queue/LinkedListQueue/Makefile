objects=test_linked_list_queue.o linked_list_queue.o

test_linked_list_queue:$(objects)
	gcc -Wall -o test_linked_list_queue $(objects) -lcheck -lsubunit -lm

test_linked_list_queue.o:test_linked_list_queue.c
	gcc -c test_linked_list_queue.c

linked_list_queue.o:linked_list_queue.c
	gcc -c linked_list_queue.c

.PHONY:check run memcheck

check:
	checkmk test_linked_list_queue.ck > test_linked_list_queue.c

run:
	./test_linked_list_queue

memcheck:
	valgrind --leak-check=full ./test_linked_list_queue --show-leak-kinds=all