#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class MultStatement: public Statement
{
private:
	std::string var;
	std::string val; // stored as string initially, until I determine if it's a variable or int


public:
	MultStatement(std::string m_variableName, std::string m_value);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

