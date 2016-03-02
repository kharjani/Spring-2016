CXX = g++
CPPFLAGS = -g -Wall

all: Facile

Facile: Statements Facile.o stack.o llistint.o ProgramState.o AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o
	$(CXX) $(CPPFLAGS) Facile.o stack.o llistint.o ProgramState.o AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o

Statements: AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o

Facile.o: Facile.cpp
	$(CXX) $(CPPFLAGS) -c Facile.cpp -o Facile.o

AddStatement.o: AddStatement.cpp AddStatement.h 
	$(CXX) $(CPPFLAGS) -c AddStatement.cpp -o AddStatement.o

LetStatement.o: LetStatement.cpp LetStatement.h 
	$(CXX) $(CPPFLAGS) -c LetStatement.cpp -o LetStatement.o

SubStatement.o: SubStatement.cpp SubStatement.h 
	$(CXX) $(CPPFLAGS) -c SubStatement.cpp -o SubStatement.o

MultStatement.o: MultStatement.cpp MultStatement.h 
	$(CXX) $(CPPFLAGS) -c MultStatement.cpp -o MultStatement.o

DivStatement.o: DivStatement.cpp DivStatement.h 
	$(CXX) $(CPPFLAGS) -c DivStatement.cpp -o DivStatement.o

ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c ProgramState.cpp -o ProgramState.o

stack.o: stack.cpp stackint.h
	g++ -g -Wall -c stack.cpp -o stack.o

llistint.o: llistint.cpp llistint.h
	g++ -g -Wall -c llistint.cpp -o llistint.o

.PHONY: clean
clean:
	rm -rf AddStatement.o
	rm -rf LetStatement.o
	rm -rf SubStatement.o
	rm -rf MultStatement.o
	rm -rf DivStatement.o
	rm -rf ProgramState.o
	rm -rf stack.o
	rm -rf Facile.o
	rm -rf llistint.o
