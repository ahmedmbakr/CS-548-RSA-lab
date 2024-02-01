.DEFAULT_GOAL := all

all: bn_sample task1 task2 task3 task4 task5 task6

bn_sample: bn_sample.c
	gcc bn_sample.c -o outputs/bn_sample -lcrypto

task1: task1.c
	gcc task1.c -o outputs/task1 -lcrypto

task2: task2.c
	gcc task2.c -o outputs/task2 -lcrypto

task3: task3.c
	gcc task3.c -o outputs/task3 -lcrypto

task4: task4.c
	gcc task4.c -o outputs/task4 -lcrypto

task5: task5.c
	gcc task5.c -o outputs/task5 -lcrypto

task6: task6.c
	gcc task6.c -o outputs/task6 -lcrypto

run_sample: bn_sample.c
	./outputs/bn_sample

run_task1: task1.c
	./outputs/task1

run_task2: task2.c
	./outputs/task2

run_task3: task3.c
	./outputs/task3

run_task4: task4.c
	./outputs/task4

run_task5: task5.c
	./outputs/task5

run_task6: task6.c
	./outputs/task6

clean:
	rm -f outputs/* *.o
