#include <iostream>
#include <fstream>
#include <cstring> 
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream input;
	input.open(argv[1]);
   
 	int n; // number of words
	input >> n;
	string *words = NULL;
	
	words = new string[n];
	
	for (int i=0; i < n; i++){
		string word;
		input >> word;
		words[i] = word;
	}
	
	for (int i=n-1; i >= 0; i--){
		cout << words[i] << endl;
	}

	delete [] words;

	return 0;
}