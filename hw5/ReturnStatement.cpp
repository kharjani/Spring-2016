#include "ReturnStatement.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

ReturnStatement::ReturnStatement(){
}


void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	int newLine = state->popFromStack();

	if(newLine != -1){
		state->setLineNum(newLine);
	}
	else{
		state->setLineNum(0);
	}

}


