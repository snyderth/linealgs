CC=g++
FLAGS=-lm -I /usr/include/Python2.7/

test: linalgs.o test_linalgs.o
	$(CC) -o test_linalgs linalgs.o test_linalgs.o 
	
linalgs.o: linalgs.cpp
	$(CC) -c linalgs.cpp

clean:
	rm -f test_linalgs *.o
	