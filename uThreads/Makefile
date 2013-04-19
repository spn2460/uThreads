all: uThreads

uThreads: queue.o uthreads.o main.o
	gcc -o bin/uThreads bin/queue.o bin/uthreads.o bin/main.o

queue.o: src/queue.c
	gcc -o bin/queue.o -c src/queue.c

uthreads.o: src/uthreads.c
	gcc -o bin/uthreads.o -c src/uthreads.c

main.o: src/main.c include/queue.h include/uthreads.h
	gcc -o bin/main.o -c src/main.c

run: bin/uThreads
	./bin/uThreads

clean:
	rm -rf bin/*.o

mrproper:
	rm -rf bin/uThreads
