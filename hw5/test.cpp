#include <iostream>
#include <string>
#include <vector>
#include "msort.h"

using namespace std;

int main(){

	vector<int> intArray;
	for(int i=10; i > 0; i--){
		intArray.push_back(i);
	}
	vector<string> strArray;
	strArray.push_back("DRESFKRBJ");
	strArray.push_back("APPLE");
	strArray.push_back("zzz");
	strArray.push_back("JUNE");
	strArray.push_back("PIE");
	
	
	StringLexiComp comp1;
	StringSizeComp comp2;
	IntComp comp3;

	mergeSort(strArray, comp1);
	cout << "String Lexi Compare:" << endl;
	for(int i=0; i < strArray.size(); i++){
		cout << strArray[i] << endl;
	}
	mergeSort(strArray, comp2);
	cout << "String Size Compare:" << endl;
	for(int i=0; i < strArray.size(); i++){
		cout << strArray[i] << endl;
	}
	mergeSort(intArray, comp3);
	cout << "Int Compare:" << endl;
	for(int i=0; i < intArray.size(); i++){
		cout << intArray[i] << endl;
	}
	

	return 0;
	
}
