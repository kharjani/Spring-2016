// LetStatement.cpp:
#include "LetStatement.h"
#include <iostream>
using namespace std;

LetStatement::LetStatement(string m_variableName, int m_value)
	: var( m_variableName ), val( m_value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	state->setVal(var, val);
	state->incrementCounter();
}


