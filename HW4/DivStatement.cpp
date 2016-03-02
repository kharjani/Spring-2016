#include "DivStatement.h"
#include <string>
#include <sstream>
using namespace std;

DivStatement::DivStatement(string m_variableName, string m_value){
	var = m_variableName;
	val = m_value;
}


void DivStatement::execute(ProgramState * state, ostream &outf)
{
	if(state->isVariable(val)){ // if 'val' is a variable which has its own int val in the map
		int curr = state->getVal(var); // current value of var (which is what will be updated)
		int divider = state->getVal(val); // int that var will be divided by
		state->setVal(var, curr / divider); // update value of var
	}	
	else{ // if 'val' is a direct integer
		stringstream stream(val);
		int divider; // what var will be divided by
		stream >> divider; // convert to int
		int curr = state->getVal(var);
		state->setVal(var, curr / divider);
	}
	state->incrementCounter();
}


