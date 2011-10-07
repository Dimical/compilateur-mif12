prog: lexer.o parser.o main.o
	g++ -o prog parser.o lexer.o main.o -lfl

lexer.o: lexer.cpp
	g++ -o lexer.o -c lexer.cpp

lexer.cpp: lexer.l parser.cpp
	flex -o lexer.cpp lexer.l

parser.o: parser.cpp
	g++ -o parser.o -c parser.cpp

parser.cpp: parser.y
	bison -d -o parser.cpp parser.y

main.o: main.cpp parser.hpp
	g++ -o main.o -c main.cpp

clean:
	rm *.o  *.h prog