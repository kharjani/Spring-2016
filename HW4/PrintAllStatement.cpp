#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement()
{}


void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
	vector<string> keys = state.getKeys();
	vector<int> values = state.getValues();
	for(int i=0; i < keys.size(); i++){
		outf << keys[i] << " " << values[i] << endl;
	}
	state->incrementCounter();
}


