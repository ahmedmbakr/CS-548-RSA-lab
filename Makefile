.DEFAULT_GOAL := all

all: bn_sample task1

bn_sample: bn_sample.c
	gcc bn_sample.c -o outputs/bn_sample -lcrypto

task1: task1.c
	gcc task1.c -o outputs/task1 -lcrypto

run_sample: bn_sample.c
	./outputs/bn_sample

run_task1: task1.c
	./outputs/task1

clean:
	rm -f outputs/* *.o
