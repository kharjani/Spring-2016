#include "AddStatement.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

AddStatement::AddStatement(string m_variableName, string m_value){
	var = m_variableName;
	val = m_value;
}


void AddStatement::execute(ProgramState * state, ostream &outf)
{
	if(state->isVariable(val)){ // if 'val' is a variable which has its own int val in the map
		int curr = state->getVal(var); // current value of var (which is what will be updated)
		int addition = state->getVal(val); // int that will be added to var
		state->setVal(var, curr+addition); // update value of var
	}	
	else{ // if 'val' is a direct integer
		stringstream stream(val);
		int addition; // what will be added
		stream >> addition; // convert to int
		int curr = state->getVal(var);
		state->setVal(var, curr+addition);
	}
	state->incrementCounter();
}


