// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: var( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << state.getVal(var) << endl;
	state->incrementCounter();
}


