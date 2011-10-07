prog: lexer.o parser.o
	gcc -o compil parser.o lexer.o -lfl

exem.o: lexer.c
	gcc -o lexer.o -c lexer.c

exem.c: lexer.l parser.c
	flex -o lexer.c lexer.l

exemple.o: parser.c
	gcc -o parser.o -c parser.c

exemple.c: parser.y
	bison -d -o parser.c parser.y

clean:
	rm *.o *.c *.h compil