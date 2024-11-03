# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

run-exec1: exec1
	./exec1
run-exec2: exec2
	./exec2

exec1: p1.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
exec2: p2.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f exec1 exec2
