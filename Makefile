CC = g++
CFLAGS = -Wall -Wextra -O3 -pedantic

all: Generator.x BubbleSort.x SelectionSort.x InsertionSort.x Benchmark.x CountingSort.x

BubbleSort.x: BubbleSort.cpp
	$(CC) $(CFLAGS) -o BubbleSort.x BubbleSort.cpp

SelectionSort.x: SelectionSort.cpp
	$(CC) $(CFLAGS) -o SelectionSort.x SelectionSort.cpp

InsertionSort.x: InsertionSort.cpp
	$(CC) $(CFLAGS) -o InsertionSort.x InsertionSort.cpp

Generator.x: Generator.cpp
	$(CC) $(CFLAGS) -o Generator.x Generator.cpp
Benchmark.x: Benchmark.cpp
	$(CC) $(CFLAGS) -o Benchmark.x Benchmark.cpp
CountingSort.x: CountingSort.cpp
	$(CC) $(CFLAGS) -o CountingSort.x CountingSort.cpp
Generate:
	./Generator.x 10000 100000 > input_10k.txt

BubbleSort:
	./Generator.x 10000 100000 | ./BubbleSort.x

SelectionSort:
	./Generator.x 10000 100000 | ./SelectionSort.x

InsertionSort:
	./Generator.x 10000 100000 | ./InsertionSort.x

CountingSort:
	./Generator.x 1000000 100000 | ./CountingSort.x
Benchmark:
	./Generator.x 200000 100000 | ./Benchmark.x

clean:
	rm -f *.x