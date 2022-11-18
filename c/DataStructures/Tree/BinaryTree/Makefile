objects=test_binary_tree.o binary_tree.o

test_binary_tree:$(objects)
	gcc -Wall -o test_binary_tree $(objects) -lcheck -lsubunit -lm

test_binary_tree.o:test_binary_tree.c
	gcc -c test_binary_tree.c

binary_tree.o:binary_tree.c
	gcc -c binary_tree.c

.PHONY:check run memcheck debug

check:
	checkmk test_binary_tree.ck > test_binary_tree.c

run:
	./test_binary_tree

memcheck:
	valgrind --leak-check=full ./test_binary_tree --show-leak-kinds=all

debug:
	checkmk test_binary_tree.ck > test_binary_tree.c && make && make run