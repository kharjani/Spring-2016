#include "ProgramState.h"
using namespace std;

ProgramState::ProgramState(int m_numLines){
	programCounter = 0;
	numLines = m_numLines;
}

int ProgramState::getVal(string key){
	unsigned int size = map.size();
	int curr = map[key];
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
	map<string,int>::iterator it;
	for (it=map.begin(); it!=map.end(); ++it){
    	keys.push_back(it->first);
	}
	return keys;

}

vector<int> ProgramState::getValues(){
	vector<int> values;
	map<string,int>::iterator it;
	for (it=map.begin(); it!=map.end(); ++it){
    	values.push_back(it->second);
	}
	return values;
}

void ProgramState::setLineNum(int lineNum){
	
}
/*
bool ProgramState::exists(string key){
	map<string,int>::iterator it;
	for (map<string,int>::iterator it=map.begin(); it!=map.end(); ++it){
    	if (it->first == key){ // if a matching key is found
    		return true;
    	}
	}
    return false;
} */