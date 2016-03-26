#include "IfStatement.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

IfStatement::IfStatement(string m_variableName, string oper, int value, int newLine){
	var = m_variableName;
	val = value;
	op = oper;
	newLineNum = newLine;
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


