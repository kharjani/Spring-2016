#include "ProgramState.h"
#include <iostream>
using namespace std;

ProgramState::ProgramState(int m_numLines){
	programCounter = 1;
	numLines = m_numLines;
	stack = new StackInt();
}



int ProgramState::getVal(string key){
	unsigned int size = map.size();
	int curr = map[key]; // curr won't be used, it's just to see if map.size() changes
	curr++; // to suppress the compiler warning that it is unused
	if (size != map.size()){ // if size has changed it means map[key] wasn't in the map but has now been created with a default value
		map[key] = 0;
	}
	return map[key];
	
}

void ProgramState::setVal(string key, int val){
	map[key] = val; // if map[key] doesn't exist, the [] operator will create it and now set it's value to val
}

bool ProgramState::isVariable(string value){ // used to check if 'value' is a string variableName (otherwise it is a number)
	if (isalpha(value[0]) != 0){
		return true;
	}
	else{
		return false;
	}
}

void ProgramState::incrementCounter(){
	programCounter++;
}

vector<string> ProgramState::getKeys(){
	vector<string> keys;
	typename map<string,int>::iterator it;
	for (it=map.begin(); it!=map.end(); ++it){
    	keys.push_back(it->first);
	}
	return keys;

}

vector<int> ProgramState::getValues(){
	vector<int> values;
	typename map<string,int>::iterator it;
	for (it=map.begin(); it!=map.end(); ++it){
    	values.push_back(it->second);
	}
	return values;
}

void ProgramState::setLineNum(int lineNum){
	programCounter = lineNum;
}

bool ProgramState::verifyLineNum(int lineNum){
	if(0 > lineNum || lineNum > numLines){
		return false;
	}
	else{
		return true;
	}
}
int ProgramState::getProgramCounter(){
	return programCounter;
}

void ProgramState::pushToStack(int lineNum){
	const int line = lineNum;
	stack->push(line);
}

int ProgramState::popFromStack(){
	if(stack->empty()){
		return -1;
	}
	else{
		int num = stack->top();
		stack->pop();
		return num;
	}
}
