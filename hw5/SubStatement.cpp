#include "SubStatement.h"
#include <string>
#include <sstream>
using namespace std;

SubStatement::SubStatement(string m_variableName, string m_value){
	var = m_variableName;
	val = m_value;
}


void SubStatement::execute(ProgramState * state, ostream &outf)
{
	if(state->isVariable(val)){ // if 'val' is a variable which has its own int val in the map
		int curr = state->getVal(var); // current value of var (which is what will be updated)
		int subtraction = state->getVal(val); // int that will be subtracted from var
		state->setVal(var, curr - subtraction); // update value of var
	}
	else{ // if 'val' is a direct integer
		stringstream stream(val);
		int subtraction; // what will be subtracted
		stream >> subtraction; // convert to int
		int curr = state->getVal(var);
		state->setVal(var, curr - subtraction);
	}
	state->incrementCounter();
}


