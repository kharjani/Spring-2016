#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class IfStatement: public Statement
{
private:
	std::string var;
	std::string op; // comparison operator
	int val;
	int newLineNum;


public:
	IfStatement(std::string m_variableName, std::string op, int val, int newLineNum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

