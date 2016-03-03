#include "EndStatement.h"
#include <string>
#include <sstream>
using namespace std;

EndStatement::EndStatement(){
	
}


void EndStatement::execute(ProgramState * state, ostream &outf)
{
	state->setLineNum(0);
}


