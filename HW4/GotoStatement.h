#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GotoStatement: public Statement
{
private:
	int numLines;
	
public:
	GotoStatement(int numLines);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

