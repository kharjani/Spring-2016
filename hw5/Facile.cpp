// Facile.cpp

#include "Facile.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <map>


using namespace std;

void parseProgram(istream& inf, vector<Statement *> & program);
Statement * parseLine(string line);

Facile::Facile(string file){
	filename = filename;
	inf = ifstream infile(filename.c_str());
	outf = cout;
    if (!infile){goodFile = false;}

    parseProgram();
    

    
}

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.


// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.


bool Facile::verifiedFile(){
	return goodFile;
}

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!



/*
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cerr << "Program usage: ./Facile inputFile outputFile" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);
    if (!inFile)
    {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return 1;
    }
    if(!outFile)
    {
        std::cerr << "Could not open file " << argv[2] << std::endl;
        return 1;
    }

    interpretProgram(inFile, outFile);
    inFile.close();
    outFile.close();

    return 0;
}
*/




void Facile::parseProgram()
{
	program.push_back(NULL);
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		QString codeLine = line;
		code << line;
		program.push_back( parseLine( line ) );
	}
}


Statement * Facile::parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	int val;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		//cout << "about to LET: " << var << val << endl;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	// Incomplete;  TODO:  Finish this function!
	else if (type == "PRINT"){
		ss >> var;
		statement = new PrintStatement(var);
		
	}
	else if (type == "PRINTALL"){
		statement = new PrintAllStatement();

	}
	else if (type == "ADD"){
		ss >> var;
		string temp;
		ss >> temp; // at this point temp could refer to a variable or an int, I will figure this out in the execute function for AddStatement
		statement = new AddStatement(var, temp);
		
	}
	else if (type == "SUB"){
		ss >> var;
		string temp;
		ss >> temp; // at this point temp could refer to a variable or an int, I will figure this out in the execute function for SubStatement
		statement = new SubStatement(var, temp);
		
	}
	else if (type == "MULT"){
		ss >> var;
		string temp;
		ss >> temp; // at this point temp could refer to a variable or an int, I will figure this out in the execute function for SubStatement
		statement = new MultStatement(var, temp);
		
	}
	else if (type == "DIV"){
		ss >> var;
		string temp;
		ss >> temp; // at this point temp could refer to a variable or an int, I will figure this out in the execute function for SubStatement
		statement = new DivStatement(var, temp);
	}
	else if (type == "GOTO"){
		ss >> val;
		statement = new GotoStatement(val);
	}
	else if (type == "IF"){
		ss >> var;
		string op;
		int num;
		int lineNum;
		string then;
		ss >> op >> num >> then >> lineNum;
		statement = new IfStatement(var, op, num, lineNum);
	}
	else if (type == "GOSUB"){
		ss >> val;
		statement = new GoSubStatement(val);
	}
	else if (type == "RETURN"){
		statement = new ReturnStatement();
		
	}
	else if (type == "END" || type == "."){
		statement = new EndStatement(); 
	}
		
	return statement;
}


void Facile::interpretProgram()
{
	//create program state, pass it and the ostream into the execute function
	parseProgram( inf, program );
	ProgramState * state = new ProgramState(program.size());
	//while loop - while program counter is not 0, call the execute function
	while(state->getProgramCounter() != 0){
		program[state->getProgramCounter()]->execute(state, outf);
	}
	
}

QStringList* Facile::getCode(){
	return code;
}

void Facile::continue(QList* breakLines){
	while((!breakLines.contains(state->getProgramCounter)
		&& (state->getProgramCounter() != 0)){
		program[state->getProgramCounter()]->execute(state, outf);
	}
}

void Facile::step(){
	program[getProgramCounter()]->execute(state, outf);
}

void Facile::next(bool isGosub, QList* breakLines){
	int curr = state->getProgramCounter();
	if(isGosub){
		while((state->getProgramCounter() != curr+1) && (!breakLines.contains(state->getProgramCounter))){
		program[state->getProgramCounter()]->execute(state, outf);
		}
	}
	else{
		program[getProgramCounter()]->execute(state, outf);
	}
}

int Facile::getCurrentLine(){
	return state->getProgramCounter();
}

map<string, int>* Facile::getMap(){
	map<string, int> *map;
	vector<int> values = state->getValues();
	vector<string> keys = state->getKeys();
	for(int i=0; i < values.size(); i++){
		map->insert(pair<string, int>(keys[i],values[i]));
	}
	return map;
}


