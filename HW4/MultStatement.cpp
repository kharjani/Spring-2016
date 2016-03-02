#include "MultStatement.h"
#include <string>
#include <sstream>
using namespace std;

MultStatement::MultStatement(string m_variableName, string m_value){
	var = m_variableName;
	val = m_value;
}


void MultStatement::execute(ProgramState * state, ostream &outf)
{
	if(state->isVariable(val)){ // if 'val' is a variable which has its own int val in the map
		int curr = state->getVal(var); // current value of var (which is what will be updated)
		int multiplier = state->getVal(val); // int that will be multiplied to var
		state->setVal(var, curr*multiplier); // update value of var
	}	
	else{ // if 'val' is a direct integer
		stringstream stream(val);
		int multiplier; // what will be multiplied
		stream >> multiplier; // convert to int
		int curr = state->getVal(var);
		state->setVal(var, curr*multiplier);
	}
	state->incrementCounter();
}


