all: runMovies tests
runMovies: main.o movies.o
	g++ main.o movies.o -o runMovies 
tests: tests.o movies.o
	g++ tests.o movies.o -o tests
clean:
	rm runMovies *.o
	rm tests *.o
	 
