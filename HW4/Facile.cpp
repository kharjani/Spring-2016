// Facile.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "PrintStatement.h"
#include "PrintAllStatement.h"
#include "GoSubStatement.h"
#include "GotoStatement.h"
#include "EndStatement.h"
#include "ReturnStatement.h"
#include "IfStatement.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <cstdlib>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
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


void interpretProgram(istream& inf, ostream& outf)
{
	//create program state, pass it and the ostream into the execute function
	vector<Statement *> program;
	parseProgram( inf, program );
	ProgramState * state = new ProgramState(program.size());
	//while loop - while program counter is not 0, call the execute function (no need for loop)
	int i=1;
	while(state->getProgramCounter() != 0){
		program[i]->execute(state, outf);
		i++;
	}
	
}

