#include "GotoStatement.h"

GotoStatement::GotoStatement(int lineNum)
	: lineNum( lineNum )
{}


void GotoStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << state.getVal(var) << endl;
	state->incrementCounter();
}


