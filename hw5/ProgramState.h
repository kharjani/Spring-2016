// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include <string>
#include <map>
#include <vector>
#include "stackint.h"

class ProgramState
{
public:
	ProgramState(int m_numLines);

	int getVal(std::string key);

	void setVal(std::string key, int val);

	bool isVariable(std::string value);

	void incrementCounter();

	std::vector<std::string> getKeys(); // returns a string array with all the keys

	std::vector<int> getValues(); // returns an int array with all the values

	void setLineNum(int numLine);

	bool verifyLineNum(int LineNum);

	int getProgramCounter(); 

	void pushToStack(int lineNum);

	int popFromStack();

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.


private:
	int numLines;
	std::map<std::string, int> map;
	int programCounter; 
	StackInt *stack;

};

#endif



