#include "ReturnStatement.h"
#include <string>
#include <sstream>
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
		outf << "Illegal jump instruction." << endl;
		state->setLineNum(0);
	}

}


