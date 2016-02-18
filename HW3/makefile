all: llistint parser


parser: parser.cpp stack
	g++ -g -Wall parser.cpp -o parser

stack: stack.cpp llistint.cpp llistint.h stackint.h
	g++ -g -Wall stack.cpp -o stack

llistint: llistint.cpp llistint.h
	g++ -g -Wall llistint.cpp -o llistint

clean:
	rm llistint
	rm parser

