#include "PrintAllStatement.h"
#include <vector>
using namespace std;


PrintAllStatement::PrintAllStatement()
{}


void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
	vector<string> keys = state->getKeys();
	vector<int> values = state->getValues();
	int size = keys.size();
	for(int i=0; i < size; i++){
		outf << keys[i] << " " << values[i] << endl;
	}
	state->incrementCounter();
}


