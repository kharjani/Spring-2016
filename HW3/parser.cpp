#include "llistint.h"
#include "stackint.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
	ifstream input(argv[1]);
	string line;
	StackInt * stack = new StackInt();
	bool check = true; // check is true if the line is valid (not malformed)
	while(getline(input, line)){
		if(line == "" || line == " ") continue; // if empty line, or one contining a space
		stringstream ss;
		ss >> line;
		char ch;
		while(!ss.fail() || check){
			ss << ch;
			if(ch == " ") continue; // to skip whitespace
			if(int(ch) >= 48 && int(ch) <= 57){  // if the char is a number
				stringstream intStream; // intStream will help turn char digits into an actual number
				intStream >> ch; 
				while(int(ch) >= 48 && int(ch) <= 57){ // while the following char's are numbers
					ss << ch;
					if(ch == " ") break; // if there's whitespace 
					intStream >> ch;
				}
				int number;
				intStream << number;
				stack.push(number);
			} 
			if (int(ch) == 43) stack.push(-1); // '-1' is used in the stack to represent the + operator
			else if(int(ch) == 42) stack.push(-2); // '-2' used for the '*' operator
			else if(int(ch) == 60) stack.push(-3); // '-3' used for the '<' operator
			else if(int(ch) == 62) stack.push(-4); // '-4' used for the '>' operator
			else if(int(ch) == 40) stack.push(-5); // '-5' used for the '(' open paranthesis

			if(ch == ')'){
				int w = stack.top();
				if(w < 0){ // if it is not a number, but an operator instead
					cout << "Malformed" << endl;
					check = false;
					break;
				}
				else{
					stack.pop();
					int x = stack.top();
					if(x == -3 || x == -4){ // if '<' or '>'
						if (x==-3) w*=2; // < operator, must multiply by 2
						else {w=floor(w/2)}; // > operator, must divide by 2
					}
					else{
						if (x >= 0){ // you can't have 2 numbers in a row without operators or parentheses -> malformed
							cout << "Malformed" << endl;
							check = false;
							break;
						}
						else{ // where x is either '+' or '*', in the for -1 or -2 respectively
							stack.pop();
							int y = stack.top();
							if(y==-1 || y==-2){ // can't have 2 (+ or *) operators in a row -> malformed
								cout << "Malformed" << endl;
								check = false;
								break;
							}
							if(y>0){ // if y is a number
								if(x == -1) w +=y;
								else if(x == -2) {w*=y;}
							}
							stack.pop();
							int z = stack.top();
							if (z == -5){ // if z is a '(' , then we can process whats inside the current parentheses set
								stack.pop();
								stack.push(w); // add the processed number back to the stack
							}

						}
						}
					}
				}
			}

		}
		if(!check) continue; // if expression is malformed, move on to the next line



	}
}

//use a string stream for the larger part (lines you get from get line)
//use another string stream to take in digits when youre extracting an integer, once you have 
// all the digits in that stream, read it back out of the stream into an int variable and it'll convert perfectly