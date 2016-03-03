#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class GoSubStatement: public Statement
{
private:
	int lineNum;

public:
	GoSubStatement(int lineNum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

