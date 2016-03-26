#include "GoSubStatement.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

GoSubStatement::GoSubStatement(int lineNum){
	targetLine = lineNum;
}


void GoSubStatement::execute(ProgramState * state, ostream &outf)
{
	if(state->verifyLineNum(targetLine)){
		int curr = state->getProgramCounter();
		state->pushToStack(curr+1); // when RETURN is called it will return to the line after respective GOSUB is called
		state->setLineNum(targetLine);

	}
	else{
		outf << "Illegal jump instruction." << endl;
		state->setLineNum(0);
	}

}


