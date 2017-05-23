lab5:main.o test.o
	g++ -o lab5 main.o test.o
test.o:test.cpp test.h
	g++ -c test.cpp
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm lab5 *.o
