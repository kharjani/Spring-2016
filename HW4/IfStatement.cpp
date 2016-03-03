#include "IfStatement.h"
#include <string>
#include <sstream>
using namespace std;

IfStatement::IfStatement(string m_variableName, string op, int val, int newLineNum){
	var = m_variableName;
	val = val;
	op = op;
	newLineNum = newLineNum;
}


void IfStatement::execute(ProgramState * state, ostream &outf)
{
	bool valid = state->verifyLineNum(newLineNum);

	if(op == "<"){
		if(state->getVal(var) < val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else if(op == "<="){
		if(state->getVal(var) <= val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else if(op == ">"){
		if(state->getVal(var) > val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else if(op == ">="){
		if(state->getVal(var) >= val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else if(op == "="){
		if(state->getVal(var) == val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else if(op == "<>"){
		if(state->getVal(var) != val){
			if(valid){
				state->setLineNum(newLineNum);
			}
			else{
				outf << "Illegal jump instruction." << endl;
				state->setLineNum(0);
			}
		}
		else{
			state->incrementCounter();
		}
	}
	else{
		state->incrementCounter();
	}
	
}


