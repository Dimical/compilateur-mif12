prog: lexer.o parser.o TableId.o
	g++ -o prog parser.o lexer.o TableId.o -lfl

lexer.o: lexer.cpp
	g++ -o lexer.o -c lexer.cpp

lexer.cpp: lexer.l parser.cpp
	flex -o lexer.cpp lexer.l

parser.o: parser.cpp TableId.o
	g++ -o parser.o TableId.o -c parser.cpp

parser.cpp: parser.y
	bison -d -o parser.cpp parser.y

TableId.o: TableId.cpp
	g++ -o TableId.o -c TableId.cpp

clean:
	rm *.o   prog parser.hpp parser.cpp lexer.cpp