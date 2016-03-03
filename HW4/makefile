CXX = g++
CPPFLAGS = -g -Wall

all: Facile

Facile: Statements Facile.o stack.o llistint.o ProgramState.o AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o IfStatement.o GotoStatement.o GoSubStatement.o ReturnStatement.o PrintStatement.o PrintAllStatement.o EndStatement.o
	$(CXX) $(CPPFLAGS) Facile.o stack.o llistint.o ProgramState.o AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o IfStatement.o GotoStatement.o GoSubStatement.o ReturnStatement.o PrintStatement.o PrintAllStatement.o EndStatement.o

Statements: AddStatement.o LetStatement.o SubStatement.o MultStatement.o DivStatement.o IfStatement.o GotoStatement.o GoSubStatement.o ReturnStatement.o PrintStatement.o PrintAllStatement.o EndStatement.o

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

IfStatement.o: IfStatement.cpp IfStatement.h 
	$(CXX) $(CPPFLAGS) -c IfStatement.cpp -o IfStatement.o

GotoStatement.o: GotoStatement.cpp GotoStatement.h 
	$(CXX) $(CPPFLAGS) -c GotoStatement.cpp -o GotoStatement.o

GoSubStatement.o: GoSubStatement.cpp GoSubStatement.h 
	$(CXX) $(CPPFLAGS) -c GoSubStatement.cpp -o GoSubStatement.o

ReturnStatement.o: ReturnStatement.cpp ReturnStatement.h 
	$(CXX) $(CPPFLAGS) -c ReturnStatement.cpp -o ReturnStatement.o

PrintStatement.o: PrintStatement.cpp PrintStatement.h 
	$(CXX) $(CPPFLAGS) -c PrintStatement.cpp -o PrintStatement.o

PrintAllStatement.o: PrintAllStatement.cpp PrintAllStatement.h 
	$(CXX) $(CPPFLAGS) -c PrintAllStatement.cpp -o PrintAllStatement.o

EndStatement.o: EndStatement.cpp EndStatement.h 
	$(CXX) $(CPPFLAGS) -c EndStatement.cpp -o EndStatement.o

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
	rm -rf IfStatement.o
	rm -rf GotoStatement.o
	rm -rf GoSubStatement.o
	rm -rf ReturnStatement.o
	rm -rf PrintStatement.o
	rm -rf PrintAllStatement.o
	rm -rf EndStatement.o
	rm -rf ProgramState.o
	rm -rf stack.o
	rm -rf Facile.o
	rm -rf llistint.o
