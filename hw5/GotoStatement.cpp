#include "GotoStatement.h"

GotoStatement::GotoStatement(int lineNum)
	: lineNum( lineNum )
{}


void GotoStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(state->verifyLineNum(lineNum)){
		state->setLineNum(lineNum);
	}
	else{
		outf << "Illegal jump instruction" << std::endl;
		state->setLineNum(0);
	}
}


